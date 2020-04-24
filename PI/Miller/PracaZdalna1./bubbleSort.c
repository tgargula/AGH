#include <stdio.h>
#include <stdlib.h>

const int N = 100;

void randomArray(int tab[]) {
    srand(time(0));
    for(int j = 0; j < N; j += 1) tab[j] = rand() % N;
}

void swapp(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubbleSort(int tab[]) {
    for(int i = 0; i < N; i += 1) {
        int isSorted = 1;
        for(int j = N-1; j > i; j -= 1) {
            if(tab[j] < tab[j-1]) {
                isSorted = 0; 
                swapp(&tab[j], &tab[j-1]);
            }
        }
        if(isSorted == 1) break;
    }
}

void revBubbleSort(int tab[]) {
    for(int i = 0; i < N; i += 1) {
        int isSorted = 1;
        for(int j = N-1; j > i; j -= 1) {
            if(tab[j] > tab[j-1]) {
                isSorted = 0;
                swapp(&tab[j], &tab[j-1]);
            }
        }
        if(isSorted == 1) break;
    }
}

void printArray(int tab[]) {
    for(int i = 0; i < N; i+=1) printf("%d %c", tab[i], ' ');
    printf("%c", '\n');
}

int main() {
    int tab[N];
    randomArray(tab);
    printArray(tab);
    bubbleSort(tab);
    printArray(tab);
    revBubbleSort(tab);
    printArray(tab);
    return 0;
}