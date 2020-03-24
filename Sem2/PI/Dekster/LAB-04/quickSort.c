#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getTab (int *tab, size_t n) {

    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

}

void printTab (int *tab, size_t n) {
    
    for (int i = 0; i < n; i++) printf("%d\n", tab[i]);

}

void swap (int *a, int *b) {
    
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

int partition (int *tab, int start, int end) {

    int pivot = tab[end];
    int i = start - 1;
    
    for (int j = start; j < end; j++) {
        if (tab[j] <= pivot) swap(&tab[j], &tab[++i]);
    }

    swap(&tab[end], &tab[++i]);
    
    return i;

}

int randPartition (int *tab, int start, int end) {

    int r = rand() % (end - start + 1) + start;
    swap (&tab[end], &tab[r]);
    return partition(tab, start, end);

}

void quickSortAux (int *tab, int start, int end) {

    if (start < end) {
        int pivot = randPartition(tab, start, end);
        quickSortAux(tab, start, pivot - 1);
        quickSortAux(tab, pivot + 1, end);
    }

}

void quickSort (int *tab, size_t n) {

    int start = 0;
    int end = n-1;

    quickSortAux(tab, start, end);
    
}

int main(void) {

    srand(time(NULL));
    int Z;
    scanf("%d", &Z);

    for (int i = 0; i < Z; i++) {
        int n;
        scanf("%d", &n);
        
        int *tab = malloc (n * sizeof(int));

        getTab(tab, n);
        quickSort(tab, n);
        printTab(tab, n);
    } 

    return 0;
}