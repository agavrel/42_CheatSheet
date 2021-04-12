#include <stdio.h> // notably for printf
#include <stdlib.h> // notably for malloc

void increment(int n);
int *create_and_print_int_array(int len);

int main(void) {

/* float and double are different */
    float f = 1.54321; // should be 1.54321f to assign a float value
    double d = 1.54321;
    if (f == d) // float and double are represented differently
        printf("true");


/* always initialize your variables */
    int i;
    printf("%d\n", i); // by default C value are not initialized to 0;


/* changing a variable value */
    i = 2; // you can set a variable value with an assignation
    increment(i); // either give the variable's address by passing the pointer, or returning a new value from the function.
    i++;
    printf("%f\n", i); // use printf with the correct format specifier, f is for double and float, while d is for integers.
    printf("%d\n", i); // that's much better


/* know the range of each type */
    char c = 'a';
  //  while (c < 150) // what is c type? what is c type's max value?
        c++;

    int n = -2147483648; // INT_MIN value;
    n = -n; // should print 2147483648 right?
    printf("%d\n", n);

    unsigned int m = 0xffffffff; // unsigned int max value is easily represented with 8 'f' (2 'f' = 1 byte)
    unsigned int l = (1 << 32) - 1; // will overflow, you have to write (1UL << 32)
    printf("m: %u\nl: %u\n", m, l);

    n = 0;
    //while (--n) // not as secured as writing while (--n >= 0)
        printf("%d\n", n);

    m = 5;
    // while (m --> -1) // will always be true as unsigned are always equal to 0 or superior
        printf("%d\n", m); // should be %u for unsigned

/* about using malloc */
    int *arr;
    arr = create_and_print_int_array(5);


/* about using correctly scanf */
    int a;
    scanf("%d", a); // scanf takes a pointer, you have to add &
}

// wrong way to change a variable's value:
void increment(int n) {
    n += 1; // the local value of n is modified, also it can be written as ++n; or n++;
}

// correct ways to change a variable's value:
void increment_using_ptr(int *i) { // increment_using_ptr(&i);
    *i++;
}

int increment_using_return(int i) { // i = increment_using_return(i);
    return i + 1;
}

// malloc correctly and protect it
int *create_int_array(int len) {
    int *n;
    n = (int *)malloc(len); // there are three things wrong:
    // 1: there is no need to cast the result of malloc
    // 2: you should actually malloc sizeof(int) * len, as you give to malloc a number of bytes to malloc, but integer is stored on 4 bytes
    // 3: malloc can fail, so it should be protected:
    /*if (n == NULL)
        return NULL;*/
    return n;
}

int *create_and_print_int_array(int len) {
    int *n = create_int_array(len); // if the memory allocation from the subfunction fails, no protection, should add if (n == NULL) below
    /*if (n == NULL)
        return NULL;*/
    n[5] = 5; // n[5] is equivalent to *(n + 5), problem: we have only (intended to) malloc 5 items, not 6.
    for (int i = 0; i <= len; i++) // index rightfully starts at 0 but should end at len - 1. Also sizeof(n) is not equivalent to len.
        printf("%d ", n[i]); // it can still work but it is undefined behavior.
    printf("\n");
    return n;
}