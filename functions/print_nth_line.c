// https://man7.org/linux/man-pages/man3/getline.3.html

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *stream = fopen(argv[1], "r");
    char *line = malloc(100);
    size_t len = 0;
    ssize_t nread;
    int line_nb = 5;

     while ((nread = getline(&line, &len, stream)) != -1 && --line_nb)
           ;
    fwrite(line, nread, 1, stdout);
    free(line);
    fclose(stream);
}