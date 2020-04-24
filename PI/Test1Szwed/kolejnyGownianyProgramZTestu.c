#include <stdio.h>

void what(int tab[], int size) {
    int swap = 0;
    do {
        swap = 0;
        for(int i = 0; i < size-1; i++) {
            if(tab[i]> tab[i+1]) {
                int a = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = a;
                swap = 1;
            }
        }
        printf("OK\n");
        size--;
    } while(swap);
}

int main() {
    int tab[10] = {12, 3,7,6,2,2};
    what(tab,10);
    for (int i = 0; i < 10; i++) printf("%d ", tab[i]);
}