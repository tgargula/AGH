#include <stdio.h>

int howManyOnesInBinary (int n) {
    int ctr = 0;
    while (n > 0) {
        if (n % 2 == 1) ctr++;
        n /= 2;
    }
    return ctr;
}

int main(void) {
    int n;
    scanf("%d", &n);
    int x = howManyOnesInBinary(n);
    printf("%d\n", x);
    return 0;
}