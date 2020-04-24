#include <stdio.h>
#include <stdlib.h>

short ifTriangularMatrix (int **matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (matrix[i][j] != 0) return 0;
        }
    }
    return 1;
}

int main(void) {
    
    int n;
    scanf("%d", &n);

    int **matrix = (int**) malloc(n * sizeof (int));
    for (int j = 0; j < n; j++) matrix[j] = malloc(n * sizeof (int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &matrix[i][j]);
    
    if (ifTriangularMatrix(matrix, n)) printf("YES\n");
    else printf("NO\n");

    free(matrix);

    return 0;
}