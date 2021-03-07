#include <stdio.h>

int t[256],i;
int main(int c)
{
volatile char *const chptr;
    for(;c+3;)
    {
    printf("%d\n" , c);
        (i=getchar())>10?t[i]+=c:(c-=2);
        printf("%d\n" , c);
}
    for(i=257;--i&&!t[i-1];);
    puts(i?"false":"true");
}