void swap_bits_mask(int *a, int *b, int mask)
{
    *a ^= *b & mask;
    *b ^= *a & mask;
    *a ^= *b & mask;
}

int main(void) {
    int a = 0b00011111;
    int b = 0b10001100;
    int m = 0b00011100;

    printf("%d %d\n", a,b);
    swap_bits_mask(&a, &b, m);
    printf("%d %d\n", a,b);


    return 0;
}

/*
checked with:
    int c = 0b00001111;
    int d = 0b10011100;
    printf("%d %d\n", c,d);
*/