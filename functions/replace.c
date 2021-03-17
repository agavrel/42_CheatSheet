#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <time.h>

// gcc -O3 replace.c && ./a.out

void replace(char *s, char from, char to, long n) {
    char eq;
    while (n--) {
        eq = !(*s ^ from);
        *s = !eq * *s + eq * to;
        s++;
    }
}

void replace_branching(char *s, char from, char to, long n) {
    while (n--) {
        if (*s == from)
            *s = to;
        s++;
    }
}

void read_file_to_buffer(FILE *f, long length) {
    char buffer[length + 1];
    fseek(f, 0, SEEK_SET);
    void (*fptr[2]) (char *s, char from, char to, long n) = {replace_branching, replace};

    if (fread (buffer, 1, length, f) ) {
        buffer[length] = '\0';
        fclose (f);

        char subbuff[33];
        subbuff[32] = '\0';
        char from = 'A';
        char to = '8';
        clock_t start, end;
        double cpu_time_used[2];
        for (int j = 0; j < 2; j++){
            start = clock();
            for (int i = 0; i < 0x20 + 26; i++) {
                fptr[j](buffer, from + i, to, length);
                //memcpy( subbuff, &buffer[0], 32 );
                //printf("Modified: %s\n", subbuff);
            }
            end = clock();
            cpu_time_used[j] = ((double) (end - start)) / CLOCKS_PER_SEC;
            printf("Time: %fs\n", cpu_time_used[j]);
        }
        printf("Without branching it is %fx faster\n", cpu_time_used[0] / cpu_time_used[1]);
    }
}

int main(void)
{
    FILE * f;
    long length;
    if ((f = fopen ("test.txt", "rb"))) // NB: test.txt is a file of 8,286,208 bytes
    {
      fseek (f, 0, SEEK_END);
      read_file_to_buffer(f, ftell(f));
    }
    return 0;
}

/*
    Time: 0.475005s
    Time: 0.070859s
    Without branching it is 6.703524x faster
*/

