#include <stdio.h>

int main(void) {
	int a = 5;	// declaring an integer variable and assigning the value of 5
	int *ptr;	// declaring a pointer to integer
	int b;		// declaring an integer variable

	ptr = &a;	// pointer ptr points to what is stored at the memory address of variable a
	b = a;		// b will take the value and not the address

	a = 42;		// b is still equal to 5, but ptr will return 42, which is the value now stored at a's location;

	printf("a's value: %d, a's address: %p\n", a, &a);
	printf("ptr's value: %d, ptr's address: %p\n", *ptr, ptr); // you will get the same as above, notice that you have to dereference the pointer with * to get the value, and using the pointer alone (ptr) will give you the memory address.
	printf("b's value: %d, b's address %p\n", b, &b);

	return 0;
}
