#include <iostream>

using namespace std;

int main (void) {
    const int i = 24;
    int* ptr;
    ptr = (int *)&i;
    *ptr = 12;  // UB
    std::cout << "value at ptr: " << *ptr << std::endl;
    std::cout << "value at i: " << i << std::endl;
    printf("%p address of ptr\n%p address of i\nIs it witchcraft?\n\n", ptr, &i);

    char s[64] = "Ave Caesar, Morituri te salutant\0";
    std::cout << s << std::endl;
    ptr = (int *)s;
    *ptr = 0x20657661; // OK write " eva" at address of s, reversed because of little endianness.
    std::cout << s << " (modified string)" << std::endl; // now with lowercase 'a'
    printf("%p address of ptr\n%p address of s\n\n", ptr, s);

    const char *str  = "Ave Caesar, Morituri te salutant\0"; // in .text segment
    ptr = (int *)str;
    printf("%p address of ptr\n%p address of s\n\n", ptr, str);
    std::cout << str << " (read-only)" << std::endl;
    *ptr = 0x20657661; // attempt to write on read-only memory -> segmentation fault
    std::cout << str << std::endl;
    printf("%p\n%p\n", ptr, s);
    return 0;
}
