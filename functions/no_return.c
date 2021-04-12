#include <stdio.h>

f(n) {*&n*=2;}

int main(void) {
    printf("%d\n", f(0b10101));
}