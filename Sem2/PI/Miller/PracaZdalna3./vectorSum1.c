// Pytania: 
// - Jaka jest minimalna liczba parametrów tej funkcji (czyli - jaką najmniejszą informacji koniecznie trzeba przekazać do funkcji)?
// Odp.: Można zdefiniować dodatkowego structa przechowującego obydwie tablice lub złączyć dwie (+dodać pola na wynik) tablice tych samych rozmiarów ze sobą - wtedy przekazujemy 2 parametry: strukturę/wskaźnik na tablicę + rozmiar tablicy (pojedynczej)
// - Czy w funkcji, dla rozpoznania długości tablicy, można użyć operatora sizeof?
// Odp.: 

#include <stdio.h>

void vectorsSum(int toSum[], int arrSize) {
    for(int i = 0; i < arrSize; i += 1) {
        toSum[2*arrSize + i] = toSum[i] + toSum[arrSize + i];
    }
}

int main() {
    int a1[6] = {1, 2, 3, 4, 5, 9999}, a2[6] = {1}, b1[] = {442235}, b2[] = {900000};
    int arrSize = *(&a1 + 1) - a1;
    int toSum[3*arrSize];
    for(int i = 0; i < arrSize; i += 1) { toSum[i] = a1[i]; toSum[arrSize+i] = a2[i]; toSum[2*arrSize + i] = 0; }
    vectorsSum(toSum, arrSize);
    int j = 0;
    while(j < arrSize) { printf("%d ", toSum[j]); j++; }
    printf("\n");
    while(j < arrSize*2) { printf("%d ", toSum[j]); j++; }
    printf("\n");
    while(j < arrSize*3) { printf("%d ", toSum[j]); j++; }
    printf("\n");

    arrSize = *(&b1 + 1) - b1;
    int toSum2[3*arrSize];
    for(int i = 0; i < arrSize; i += 1) { toSum2[i] = b1[i]; toSum2[arrSize+i] = b2[i]; toSum2[2*arrSize + i] = 0; }
    vectorsSum(toSum2, arrSize);
        j = 0;
    while(j < arrSize) { printf("%d ", toSum2[j]); j++; }
    printf("\n");
    while(j < arrSize*2) { printf("%d ", toSum2[j]); j++; }
    printf("\n");
    while(j < arrSize*3) { printf("%d ", toSum2[j]); j++; }
    printf("\n");
    
    return 0;
}