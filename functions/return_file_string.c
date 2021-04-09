#include <stdio.h>

char *string(FILE *ifp, char s[256])
{
    fscanf(ifp, "%s", s);
}

char *string_from_file(FILE *ifp)
{
    char *s = malloc(256);
    fscanf(ifp, "%s", s);
    return s;
}


int main(int ac, char **av)
{
    FILE *ifp = fopen(av[1], "r");

    // using ptr:
    char s[256];
    string(ifp, s);
    printf("%s\n", s);

    // using malloc:
    printf("%s\n", string_from_file(ifp));
}