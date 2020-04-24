#include <stdio.h>

void vectorsSum(int toSum[]) {
    for(int i = 1; i < 3*toSum[0]+1; i += 1) {
        toSum[2*toSum[0] + i] = toSum[i] + toSum[toSum[0] + i];
    }
}

int main() {
    int a1[6] = {1, 2, 3, 4, 5, 9999}, a2[6] = {1}, b1[] = {442235}, b2[] = {900000};
    int arrSize = *(&a1 + 1) - a1; printf("arrsize = %d \n", arrSize);
    int toSum[1+3*arrSize]; 
    toSum[0] = arrSize;         //rozmiar wektora
    for(int i = 0; i < arrSize; i += 1) { toSum[i+1] = a1[i]; toSum[arrSize+i+1] = a2[i]; toSum[2*arrSize + i+1] = 0; }
    vectorsSum(toSum);
    int j = 1;
    while(j <= arrSize) { printf("%d ", toSum[j]); j++; }
    printf("\n");
    while(j <= arrSize*2) { printf("%d ", toSum[j]); j++; }
    printf("\n");
    while(j <= arrSize*3) { printf("%d ", toSum[j]); j++; }
    printf("\n");

    arrSize = *(&b1 + 1) - b1; printf("arrsize = %d \n", arrSize);
    int toSum2[1+3*arrSize];
    toSum2[0] = arrSize;
    for(int i = 0; i < arrSize; i += 1) { toSum2[i+1] = b1[i]; toSum2[arrSize+i+1] = b2[i]; toSum2[2*arrSize + i+1] = 0; }
    vectorsSum(toSum2);
    j = 1;
    while(j <= arrSize) { printf("%d ", toSum2[j]); j++; }
    printf("\n");
    while(j <= arrSize*2) { printf("%d ", toSum2[j]); j++; }
    printf("\n");
    while(j <= arrSize*3) { printf("%d ", toSum2[j]); j++; }
    printf("\n");
    
    return 0;
}