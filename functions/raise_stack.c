#define _GNU_SOURCE
#define _FILE_OFFSET_BITS 64

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

#define errExit(msg) do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char *argv[])
{
    struct rlimit old, new;
    struct rlimit *newp;
    pid_t pid;
perror("error:");
    if (!(argc == 2 || argc == 4)) {
        fprintf(stderr, "Usage: %s <pid> [<new-soft-limit> "
        "<new-hard-limit>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
perror("error:");
    pid = atoi(argv[1]); /* PID of target process */
perror("error:");
    newp = NULL;perror("error:");
    if (argc == 4) {
        new.rlim_cur = atoi(argv[2]);
        new.rlim_max = atoi(argv[3]);
     //   newp = &new; // I comment this line to avoid messing up with the processes too much;)
    }

/* Set CPU time limit of target process; retrieve and display
previous limit */
perror("error:");
long long a = prlimit(pid, RLIMIT_CPU, newp, &old);
perror("error:");
    if (a == -1)
        errExit("prlimit-1");

    printf("Previous limits: soft=%lld; hard=%lld\n", (long long) old.rlim_cur, (long long) old.rlim_max);

/* Retrieve and display new CPU time limit */
perror("error:");
    if (prlimit(pid, RLIMIT_CPU, NULL, &old) == -1)
        errExit("prlimit-2");
    printf("New limits: soft=%lld; hard=%lld\n", (long long) old.rlim_cur, (long long) old.rlim_max);

    perror("error:");
    exit(EXIT_FAILURE);
}