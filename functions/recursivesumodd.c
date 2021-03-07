 int recursiveSumNOdd(int n) {
    if (n == 1 || n == 0)
        return n;
    return 2 * n - 1 + recursiveSumNOdd(n-1);
 }

 int SumNOdd(int n) {
    return n*n;
 }


int main(void) {
     printf("%d\n", recursiveSumNOdd(2));
     printf("%d\n", SumNOdd(4));
    return 0;
}