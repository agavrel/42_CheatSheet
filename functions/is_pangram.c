#include <stdio.h>
#include<string.h>

int p(char*i){int a=64;while(++a<91)if(!strchr(i,a)&!strchr(i,a+32))return 0;return 1;}

n=63<<26;f(char*s){while(*s)n|=1<<(tolower(*s++)-97);return!~n;}

int main(void) {
    printf("%d\n", f("123abcdefghijklm NOPQrstuvWxyz"));
}