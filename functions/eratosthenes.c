#include <stdio.h>
#include <string.h>
/// unsigned char saves space compared to integer
#define bool    unsigned char
#define true    1
#define false   0
#define INT_MAX 0x7FFFFFFF
#define INT_MIN ~INT_MAX

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
void printPrimesRange(int lowerLevel, int n) {
    if (lowerLevel < 0 || n < lowerLevel) // handle misused of function
        return ;
    bool isPrime[n + 1];
    memset(isPrime, true, n + 1);
    int cnt = 0; // NB: I use the counter only for the commas and final .\n, its optional.

    if (lowerLevel <= 2 && n >= 2) { // only one even number can be prime: 2
        ++cnt;
        printf("2");
    }
    for (int i = 3; i <= n ; i+=2) { // after what only odd numbers can be prime numbers
        if (isPrime[i]) {
            if (i >= lowerLevel) {
                if (cnt++)
                    printf(", ");
                printf("%d", i); // NB: it is better to print all at once if you can improve it
            }
            for (int j = i * 3; j <= n; j+=i*2) // Eratosthenes' Algo, sieve all multiples of current prime, skipping even numbers
                isPrime[j] = false;
        }
    }
    printf(".\n");
}

int main(void) {
    int lowerLevel;
    int upperLevel;


    printf("%ld %d %d\n", sizeof(int), INT_MAX, INT_MIN);
    printf("Enter the lower limit and upper limit of the range with a space in-between:"); // space, not comma
    scanf("%d %d", &lowerLevel, &upperLevel);
    printPrimesRange(lowerLevel, upperLevel);
    return 0;
}

