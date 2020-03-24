#include <stdio.h>
#include <stdlib.h>

void printTab (char *tab, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", tab[i]);
    }
}

int main(void) {
    
    int Z;
    scanf("%d", &Z);

    for (int i = 0; i < Z; i++) {
        int n, k;
        scanf("%d%d", &n, &k);
        
        
        for (int j = 0; j < n; j++) {
            scanf("%s", &tab[j]);
        }
        printTab(tab,n);
    }

    return 0;
}