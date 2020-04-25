#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen(int a, int b) { return (int)((b - a) * drand48() + a); }

int main(void) {
    srand48(time(NULL));
    int left = 0;
    int right = 100;
    int rand = gen(left,right);
    int x;
    
    int ctr = 0;
    do {
        x = (left + right) / 2;
        if (x < rand) { left = x; }
        else if (x > rand) { right = x; }
        ctr++;
    } while (x != rand);

    printf("Znalazłem liczbę %d w %d ruchach\n", rand, ctr);

    return 0;
}