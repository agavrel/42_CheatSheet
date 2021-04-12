#include <stdio.h>


f(n){*&n=-(-n^1);}

int main(void) {
    for (int i = 0; i < 20; i++)
        printf("%d %d\n", i, f(i));
}
