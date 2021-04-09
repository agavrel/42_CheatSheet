#include <stdio.h>

void print_base(int n, int base) {
    const char *c = "0123456789abcdefghijklmnopqrstuvwxyz";

    if (n) {
        print_base(n/base, base);
        putchar(c[n % base]);
    }
}

void print_hex(int n) {
    const char *c = "0123456789abcdef";

    if (n) {
        print_base(n / 16);
        putchar(c[n % 16]);
    }
}

int main(void) {
    int n = 71;
    int base = 36;

    if (base <= 36)
        print_base(n, base);
    putchar('\n');
}