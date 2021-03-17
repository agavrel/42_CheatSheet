#include <stdio.h>


void base2(int n){
    if(n==0) { printf("\n");
        return;
        }
    base2(n/2);
    printf("%d",!!(n%2));
}



int base(int n, int mask)
{
    if(!mask) {
        printf("\n"); // we reach the end, print a line return
        return 0;
    }
    printf("%d",  !!(n & mask)); // if mask and n match, print '1', else print '0'. !! convert any value into 1, and 0 remains 0.
    return base(n, mask >> 1); // divide mask by 2, check the next bit on the right
}

int main() {
    int n;
    scanf("%d",&n);
    base2(n);
  //  base(n, 1 << (31 - __builtin_clz(n))); // call the function with a mask initialized at the same level than the most important bit of n.
    return 0;
}