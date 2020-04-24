#include <stdio.h>

int is_letter(int a) {
    if (a >= 'a' && a <= 'z') return 1;
    if (a >= 'A' && a <= 'Z') return 2;
    return -1;
}

int main () {
    if(is_letter('1')) printf("Tak\n");
    if("Ala ma kota") {
        printf("Ala ma kota");
    }
}