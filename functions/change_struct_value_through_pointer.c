#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct abc {
    uint8_t i;
    uint8_t j;
};

/*
int main(void) {
    struct abc *obj= malloc(sizeof(struct abc));
    uint8_t *j =  (uint8_t*)((char *)obj+ sizeof(uint8_t)); // remove the &
    *j = 5;
    printf("address of obj => %p - value in obj->j: %d\n",obj, obj->j);
    printf("address of   j => %p - value at j address: %d \n", j, *j);
    return 0;
}
*/



int main(void) {
    struct abc obj;
    uint8_t *j =  (uint8_t*)((char *)&obj+ sizeof(uint8_t));
    *j = 5;

    printf("address of obj => %p - value in obj.j: %d\n", &obj, obj.j);
    printf("address of   j => %p - value at j address: %d \n", j, *j);

    uint16_t *a =  (uint16_t*)((char *)j - 1);
    printf("address of   a => %p - value at a address: %x \n", a, *a); // will print j * 100 in hexa
    *a = 42 | 3 << 8;
    printf("\naddress of obj => %p - value in obj.i: %d\n", &obj, obj.i);
    printf("address of obj => %p - value in obj.j: %d\n", &(obj.j), obj.j);
    printf("address of   j => %p - value of j: %d \n", j, *j);
    return 0;
}
