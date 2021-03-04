// compile with gcc -fno-stack-protector scanf.c && ./a.out

int main(void) {
    char c[2];
    char *d;
    d = &c[2];
    scanf("%s",&c);
    c[1] = '*';
    scanf("%s", d);
    printf("%c%c%c",c[0],c[1],c[2]); // enable stack smashing
}