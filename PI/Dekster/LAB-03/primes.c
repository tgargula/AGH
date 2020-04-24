#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool nondescreasingDigits (int N) {
    
    int last = 10;
    
    while (N > 0) {

        if (N % 10 > last) return false;
        last = N % 10;
        N /= 10; 

    }
    
    return true;

}

bool isPrime (int N) {
    
    if (N < 2) return false;
    if (N == 2 || N == 3) return true;
    if (N %2 == 0 || N %3 == 0) return false;
    
    int d = 5;

    while (d <= sqrt(N)) {
        
        if (N %d == 0) return false;
        if (N %(d+2) == 0) return false;
        d += 6;

    }

    return true;

}

void printNumbers (int N) {
    
    for (int i = 2; i < N; i++) {
    
        if (nondescreasingDigits(i) && isPrime(i)) printf("%d\n", i);
    
    }

}

int main (void) {

    int N;

    scanf("%d", &N);

    printNumbers(N);

    return 0;

}