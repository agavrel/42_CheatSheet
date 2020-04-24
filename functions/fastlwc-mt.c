#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <ctype.h>
#include <errno.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <omp.h>
#include "simd.h"

#define BUFSIZE (sizeof(simd_vector) * 4096)

struct lwcount
{
	size_t lcount, wcount, ccount;
};

// fallback to non-seeking variant (from fastlwc.c) for non-seekable files
// (should also be used for short files less than 10MB or so)
struct lwcount wc(int fd)
{
	struct lwcount ret = { 0, 0, 0 };
	lcount_state lstate = LCOUNT_INITIAL;
	wcount_state wstate = WCOUNT_INITIAL;
	size_t rem = 0;
	ssize_t len;
	
	simd_vector *buf = aligned_alloc(sizeof(simd_vector), BUFSIZE);
	if (!buf) {
		perror("fastlwc: alloc");
		exit(EXIT_FAILURE);
	}

	posix_fadvise(fd, 0, 0, POSIX_FADV_SEQUENTIAL);

	do {
		len = read(fd, (char*)buf + rem, BUFSIZE - rem);
		if (len > 0) {
			rem += len;
			ret.ccount += len;
		} else if (len == 0) {
			if (!rem)
				break;
			memset((char*)buf + rem, ' ', sizeof(simd_vector) - rem);
			rem = sizeof(simd_vector);
		} else {
			if (errno == EINTR)
				continue;
			perror("fastlwc: read");
			exit(EXIT_FAILURE);
		}

		simd_vector *vp = buf;
		while (rem >= sizeof(simd_vector)) {
			ret.lcount += count_lines(*vp, &lstate);
			ret.wcount += count_words(*vp, &wstate);

			rem -= sizeof(simd_vector);
			vp++;
		}

		if (rem) // move rem leftover bytes to start of buf
			memmove(buf, vp, rem);
	} while (len);

	ret.lcount += count_lines_final(&lstate);
	ret.wcount += count_words_final(&wstate);
	
	free(buf);
	return ret;
}

// 100 lines of code and 6 levels of nesting... what's that, unreadable mess?
// self-commenting code, right?
struct lwcount wc_mt(int fd, off_t cur, off_t len)
{
	const size_t blocks = (len + BUFSIZE - 1) / BUFSIZE;
	size_t lcount = 0, wcount = 0;

#pragma omp parallel if(blocks > 1) reduction(+:lcount) reduction(+:wcount)
	{
		int tid = omp_get_thread_num(),
		    threads = omp_get_num_threads();
		// allocate a bit extra for lookback
		char *rbuf = aligned_alloc(sizeof(simd_vector),
		                           BUFSIZE + sizeof(simd_vector));
		if (!rbuf) {
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		char *buf = rbuf + sizeof(simd_vector);
		lcount_state lstate = LCOUNT_INITIAL;
		wcount_state wstate = WCOUNT_INITIAL;
		for (size_t i = 0, block; (block = i * threads + tid) < blocks; ++i) {
			const size_t offset_end = cur + (block + 1) * BUFSIZE;
			size_t bytes_left = BUFSIZE; // last block size handled later
			ssize_t len, rem = 0;
			
			if (block > 0) { // look back for whitespace for subsequent blocks
				bytes_left++;
				rem--;
			}
			
			do {
				len = pread(fd, buf + rem, bytes_left, offset_end - bytes_left);
				if (len > 0) {
					if (rem < 0 && len >= rem)
						wcount_state_set(&wstate, !isspace(buf[-1]));
					bytes_left -= len;
					rem += len;
				} else if (len == 0) {
					if (block != blocks - 1 || rem < 0) {
						fputs("unexpected end of file\n", stderr);
						exit(EXIT_FAILURE);
					}
					// not an error to reach EOF when processing last block
					memset(buf + rem, ' ', sizeof(simd_vector) - rem);
					rem = sizeof(simd_vector);
					bytes_left = 0;
				} else { // len < 0
					if (errno == EINTR)
						continue;
					perror("read");
					exit(EXIT_FAILURE);
				}

				simd_vector *vp = (simd_vector*)buf;
				while (rem >= (ssize_t)sizeof(simd_vector)) {
					lcount += count_lines(*vp, &lstate);
					wcount += count_words(*vp, &wstate);

					rem -= sizeof(simd_vector);
					vp++;
				}

				if (rem)
					memmove(buf, vp, rem);
			} while (bytes_left);

		}

		lcount += count_lines_final(&lstate);
		wcount += count_words_final(&wstate);
		free(rbuf);
	}

	return (struct lwcount){
		.lcount = lcount,
		.wcount = wcount,
		.ccount = len
	};
}

int main(int argc, char *argv[])
{
	int fd = STDIN_FILENO;
	if (argc > 1 && strcmp(argv[1], "-") != 0) {
		fd = open(argv[1], O_RDONLY);
		if (fd < 0) {
			fprintf(stderr, "'%s': %s\n", argv[1], strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	
	struct lwcount total = { 0, 0, 0 };
	off_t cur, end;
	
	if ((cur = lseek(fd, 0, SEEK_CUR)) == -1
	    || (end = lseek(fd, 0, SEEK_END)) == -1) {
		// it seems we can't seek this file, fallback to linear read
		total = wc(fd);
	} else if (end > cur) {
		total = wc_mt(fd, cur, end - cur);
	}
	
	printf(" %7zu %7zu %7zu", total.lcount, total.wcount, total.ccount);
	if (argc > 1)
		printf(" %s", argv[1]);
	putchar('\n');

	if (fd != STDIN_FILENO)
		close(fd);
}
