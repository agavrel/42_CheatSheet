#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFF_SIZE 256 // don't be greedy

int main()
{
    char s[BUFF_SIZE];
    char warehouse[BUFF_SIZE];
    char productNo[BUFF_SIZE];
    char qualifiers[BUFF_SIZE];

    printf("Hello World enter your MMOC like >ATL1203S14< \n");
    scanf("%s", s);
    int n = strlen(s);
    if (n > BUFF_SIZE)
        return 1;
    int i = 0;
    while (isalpha((unsigned char)s[i])) {
        warehouse[i] = s[i];
        i++;
    }
    warehouse[i] = '\0';
    int j = 0;
    while (isdigit((unsigned char)s[i]))
        productNo[j++] = s[i++];
    productNo[j] = '\0';
    memcpy(qualifiers,&s[i],n-i);
    qualifiers[n-i] = '\0';

    printf("warehouse: %s\n", warehouse);
    printf("product Number: %s\n", productNo);
    printf("qualifiers: %s\n", qualifiers);
    return 0;
}