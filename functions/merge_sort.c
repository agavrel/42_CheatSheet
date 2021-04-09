#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _DEBUG 1

void insertion_sort(int n, int a[n])
{
    int i, tmp, j;
    for (i = 1; i < n; i++) {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > tmp) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = tmp;
    }
    #ifdef _DEBUG
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        putchar('\n');
    #endif
}

void merge_sort(int n, int a[n], int x, int b[x], int y, int c[y])
{
    for (int i = 0; i < x; i++) // split values of a into two arrays
        b[i] = a[i];
    for (int i = 0; i < y; i++)
        c[i] = a[i+x];
    insertion_sort(x, b);
    insertion_sort(y, c);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n) {
        if (b[j] < c[k]) // you add to a the smallest between b and c.
            a[i++] = b[j++];
        else
            a[i++] = c[k++];
        if (x == j) { // if all the elements of b have filled a:
            do {
                a[i++] = c[k++]; // we proceed to fill a with c
            } while (y != k);
            break ; // the merge sorting is completed.
        }
        else if (y == k) {
            do {
                a[i++] = b[j++];
            } while (x != j);
            break ;
        }
    }
    #ifdef _DEBUG
        for (int i = 0; i < n; i++)
            printf("%d ", a[i]);
        putchar('\n');
    #endif
}


 int main(void) {
    srand ( time(NULL) );
    const int n = 100;
    int a[n];
    int b[n/2];
    int c[(n+1)/2];

    for (int i = 0; i < n; i++) // initialize with random values
        a[i] = rand() % 1000;

    merge_sort(n, a, n/2, b, (n+1)/2, c);
}