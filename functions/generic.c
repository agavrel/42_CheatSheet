typedef struct Person {
    char* name;
    int age;
}      t_Person;

struct Book {
    char* title;
    char* author;
};
#define MYTYPE(X)   _Generic((X),  char: "char", int: "int", float: "float", double: "double", struct Book: "book", struct Person: "person", default: "other")

int main(void) {
    struct Book ulysses = {"ulysses", "james"};
    printf("%s\n", MYTYPE(ulysses));
    struct Person jim;
    jim = (struct Person) {"Tom", 20};
    printf("%s\n", MYTYPE(jim));
    t_Person k = {"Tom", 10};
    printf("%s\n", MYTYPE((((t_Person){"Tom", 10}))));
    printf("%s\n", MYTYPE(k));
    printf("%s\n", MYTYPE((int){'a'}));
    printf("%s\n", MYTYPE((char){'a'}));

    float number = 42.42;
    unsigned int num_cpy;
    memcpy(&num_cpy, &number, sizeof(unsigned));
    unsigned int num_cpy2 = *(float *)&number;
    printf("Bits in num_cpy: %d    bits in num_cpy2: %d\n", __builtin_popcount(num_cpy), __builtin_popcount(num_cpy2));
    printf("%d\n", num_cpy);
    printf("%d\n", num_cpy2);

    return 0;
}