#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int factorial = 1;
    int i;
    if (N >= 15) { printf("N is too big."); return 0; }
    for (i = 2; i < N; i++) {
        factorial *= i;
    }
    printf("Factorial of %d is: %d\n", N, factorial);

    return 0;
}
