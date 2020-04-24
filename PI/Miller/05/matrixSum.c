#include <stdio.h>

void matrixSum(int *matrix1Ptr, int *matrix2Ptr, int matrixSize) {
    for(int i = 0; i < matrixSize; i += 1) *(matrix2Ptr + i) = *(matrix2Ptr + i) + *(matrix1Ptr + i);
}

int main() {        // zakładam, że na macierzach da się wykonać operacje dodawania i nie sprawdzam tego w osobnym warunku
    int matrix1[3][4] = {{1, 5, 99, -2}, {7, -5, 22, 2}, {542, -57654, 99900, 990055}}, matrix2[3][4] = {{45, -5, -99, 20}, {-7, 5, -22, 55}, {-2, 57655, -99899, -1}};
    // for(int i = 0; i < N; i += 1) for(int j = 0; j < M; j += 1) matrix1[i][j] = i+j;
    int *matrix1Ptr = matrix1, *matrix2Ptr = matrix2, matrixSize = (*(&matrix2 + 1) - matrix2) * (*(&matrix2[0] + 1) - matrix2[0]);
    
    for(int i = 0; i < (*(&matrix1 + 1) - matrix1); i += 1) {
        for(int j = 0; j < (*(&matrix1[0] + 1) - matrix1[0]); j += 1) printf("%d ", matrix1[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < (*(&matrix2 + 1) - matrix2); i += 1) {
        for(int j = 0; j < (*(&matrix2[0] + 1) - matrix2[0]); j += 1) printf("%d ", matrix2[i][j]);
        printf("\n");
    }
    printf("\n");
    matrixSum(matrix1Ptr, matrix2Ptr, matrixSize);
    for(int i = 0; i < (*(&matrix2 + 1) - matrix2); i += 1) {
        for(int j = 0; j < (*(&matrix2[0] + 1) - matrix2[0]); j += 1) printf("%d ", matrix2[i][j]);
        printf("\n");
    }
    return 0;
}