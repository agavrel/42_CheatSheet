#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct abc {
    uint8_t byte_we_want_to_skip;
    uint8_t j;
};

int main(void) {
    struct abc *obj= malloc(sizeof(struct abc));
    uint8_t **j =  (uint8_t**)((char *)obj+ sizeof(uint8_t)); // remove the &
    *j = (uint8_t*)5;
    printf("%d\n",obj->j);

    return 0;
}

/*
// or on stack:
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct abc {
    uint8_t byte_we_want_to_skip;
    uint8_t j;
};

int main(void) {
    struct abc obj;
    uint8_t **j =  (uint8_t**)((char *)&obj+ sizeof(uint8_t));
    *j = (uint8_t*)5;
    printf("%d\n",obj.j);

    return 0;
}
*/