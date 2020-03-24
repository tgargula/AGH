#include <stdio.h>
#include <stdlib.h>

inline void getTab (char **tab, int n) { for (int i = 0; i < n; i++) scanf("%s", &tab[i][0]); }

inline void printTab (char **tab, int n) { for (int i = 0; i < n; i++) printf("%s\n", tab[i]); }

inline void zeroTab (int *tab, int n) { for (int i = 0; i < n; i++) tab[i] = 0; }

inline int index (char **tab, int string, int pos) { return tab[string][pos] - '0'; }

void countingSortByPosition (char **A, int n, int k, int pos) {

    char **B;
    B = malloc (n * sizeof(char*));
    for (int j = 0; j < n; j++) B[j] = malloc (k * sizeof(char));
    
    int *C = malloc (10 * sizeof(int));
    for (int i = 0; i < 10; i++) C[i] = 0;

    for (int i = 0; i < n; i++) C[index(A, i, pos)]++;

    for (int i = 1; i < 10; i++) C[i] += C[i-1];

    for (int i = n-1; i >= 0; i--) B[--C[index(A, i, pos)]] = A[i];

    for (int i = 0; i < n; i++) A[i] = B[i];
    
    free(B);
    free(C);

}

void radixSort (char **tab, int n, int k) {

    for (int pos = k-1; pos >= 0; pos--) countingSortByPosition(tab, n, k, pos);

}

int main(void) {

    int Z;
    scanf("%d", &Z);

    for (int i = 0; i < Z; i++) {
        int n, k;
        scanf("%d%d", &n, &k);

        char **tab;
        tab = malloc (n * sizeof(char*));
        for (int j = 0; j < n; j++) tab[j] = malloc (k * sizeof(char));

        getTab(tab, n);
        radixSort(tab,n,k);
        printTab(tab,n);
        
        for (int i = 0; i < n; i++) free(tab[i]);
        free(tab);
    }

    return 0;

}