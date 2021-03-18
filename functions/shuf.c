#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int  main(int argc, char *argv[])
{
    char line[256];
    int pipefd[2];

    //dprintf(2, "%d\n", pipefd[0]);
    for (int i = 1; i < argc; i++) {
        pipe(pipefd); // set a fd for your pipes
        if (fork() == 0) {
            close(pipefd[0]);    // close reading end in the child
            dup2(pipefd[1], 1);  // send stdout to the pipe
            close(pipefd[1]);    // this descriptor is no longer needed
            execv("/usr/bin/shuf", (char *[]) {"", argv[i], NULL});
        }
        else {
            close(pipefd[1]);
            FILE *input = fdopen(pipefd[0],"r");
            int j = 0;
            while (fgets(line, sizeof(line), input))
                printf("%d: %s", j++, line);
            fclose(input);
        }
    }
    return 0;
}