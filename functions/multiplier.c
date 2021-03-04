#include <stdio.h>


unsigned add(unsigned n, unsigned result) {
    unsigned a = 0;

    do {
        a = ((n & result) << 1); // common bits, so we can safely multiply by 2
        result ^= n; // we get rid of the common bits
    } while ((n = a));

    return result;
}


/*

//http://users.utcluj.ro/~baruch/book_ssce/SSCE-Shift-Mult.pdf
Shift-and-add multiplication is similar to the multiplication performed by paper and pencil.
This method adds the multiplicand X to itself Y times, where Y denotes the multiplier.
To multiply two numbers by paper and pencil, the algorithm is to take the digits of the multiplier
one at a time from right to left, multiplying the multiplicand by a single digit of the multiplier
and placing the intermediate product in the appropriate positions to the left of the earlier results.

*/

unsigned multiply(unsigned multiplier, unsigned multiplicand) {
    unsigned result = 0;

    do { // NB: LSB is the least significant bit of multiplier, (multiplier & 1)
// The LSB of the multiplier register determines whether the multiplicand is added (if set) to the product register
        if ((multiplier & 1)
            result = add(result, multiplicand);
// The left shift of the multiplicand has the effect of shifting the intermediate products to the left, just as when multiplying by paper and pencil.
        multiplier >>= 1;
// The right shift of the multiplier prepares the next bit of the multiplier to examine in the following iteration
        multiplicand <<= 1;
    } while (multiplier);

    return result;
}


int main(void) {
    unsigned a  = multiply(6,7);
    unsigned b  = add(6,7);
    printf("%u\n", a);
    printf("%u\n", b);

    return 0;
}