#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int  sum (int len, int *value, ...) {
    va_list args; // initialize va_list

    int res = *value;
    va_start(args, *value); // start va
    for (int i = 1; i < len; i++) // iterate over other arguments
        res += (int)*va_arg(args, int*); // add the next argument to res
    va_end(args); // don't forget to end va
    return res;
}
int main(){
    int elements[8]={11,2,33,5,8,48,2,-8};
    int three_elements;
    int five_elements;
    int eight_elements;
    three_elements=sum(3, &elements[0], &elements[1], &elements[2]);
    five_elements=sum(5, &elements[0], &elements[1], &elements[2], &elements[3], &elements[4]);
    eight_elements=sum(8, &elements[0], &elements[1], &elements[2], &elements[3], &elements[4], \
        &elements[5], &elements[6], &elements[7]);
    printf("First Three elements sum:%d\n",three_elements);
    printf("First five elements sum:%d\n",five_elements);
    printf("First eight elements sum:%d\n",eight_elements);
    return 0;
}

/*

// without pointers

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int  sum (int len, int value, ...) {
    va_list args; // initialize va_list

    int res = value;
    va_start(args, value); // start va
    for (int i = 1; i < len; i++) // iterate over other arguments
        res += va_arg(args, int); // add the next argument to res
    va_end(args); // don't forget to end va
    return res;
}
int main(){
    int elements[8]={11,2,33,5,8,48,2,-8};
    int three_elements;
    int five_elements;
    int eight_elements;
    three_elements=sum(3, elements[0], elements[1], elements[2]);
    five_elements=sum(5, elements[0], elements[1], elements[2], elements[3], elements[4]);
    eight_elements=sum(8, elements[0], elements[1], elements[2], elements[3], elements[4],elements[5], elements[6], elements[7]);
    printf("First Three elements sum:%d\n",three_elements);
    printf("First five elements sum:%d\n",five_elements);
    printf("First eight elements sum:%d\n",eight_elements);
    return 0;
}

*/