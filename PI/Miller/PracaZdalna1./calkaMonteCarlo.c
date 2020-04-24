#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

const int pi = 31415962, shots = 10000000;

double MonteCarlo() {
    int hits = 0;
    srand(time(0));
    for (int i = 0; i < shots; i += 1) {
        srand(rand());
        int x = rand() % pi, y = rand() % 10000000;
        if ( sin(x) <= (double) y/10000000 ) hits += 1;
    }
    double result = (double) hits/shots;
    result *= 3.1415962;
    return result;
}

int main() {
    printf("%lf\n", MonteCarlo());
    return 0;
}