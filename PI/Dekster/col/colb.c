#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool possible(int N, int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

int main(void) {

    int N;
    scanf("%d", &N);
    int **T = malloc(N*sizeof(int*));
    for (int i = 0; i < N; i++) T[i] = malloc(N*sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) scanf("%d", &T[i][j]);
    }

    int **W = malloc(N*sizeof(int*));
    for (int i = 0; i < N; i++) W[i] = malloc(N*sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) W[i][j] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            if (possible(N,i-1,j-1))    W[i][j] += T[i-1][j-1];
            if (possible(N,i-1,j))      W[i][j] += T[i-1][j];
            if (possible(N,i-1,j+1))    W[i][j] += T[i-1][j+1];
            if (possible(N,i,j-1))      W[i][j] += T[i][j-1];
            if (possible(N,i,j+1))      W[i][j] += T[i][j+1];
            if (possible(N,i+1,j-1))    W[i][j] += T[i+1][j-1];
            if (possible(N,i+1,j))      W[i][j] += T[i+1][j];
            if (possible(N,i+1,j+1))    W[i][j] += T[i+1][j+1];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++) free(W[i]);
    free(W);


    for (int i = 0; i < N; i++) free(T[i]);
    free(T);

    return 0;
}