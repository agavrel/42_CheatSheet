#include <stdio.h>
#include <string.h>

#define bool    unsigned char
#define true    1
#define false   0
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
void printPrimes(int n) {
    if (n < 0 ) // handle misused of function
        return ;
    bool isPrime[n + 1];
    memset(isPrime, true, n + 1);
    int cnt = 0; // NB: I use the counter only for the commas and final .\n, its optional.

    if (n >= 2) { // only one even number can be prime: 2
        ++cnt;
        printf("2");
    }
    for (int i = 3; i <= n ; i+=2) { // after what only odd numbers can be prime numbers
        if (isPrime[i]) {
            if (cnt++)
                printf(", ");
            printf("%d", i); // NB: it is better to print all at once if you can improve it
        }
        for (int j = i * i; j <= n; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers
            isPrime[j] = false;
    }
    printf(".\n");
}

int main(void) {
    printPrimes(100);
    return 0;
}