#include <stdio.h>

int main(void) {
    int x = 1;

    char *y = (char*)&x;

    if (*y+48 == '1') {
        printf("It is little endian\n");
    } else printf("It is big endian\n");

    return 0;
}