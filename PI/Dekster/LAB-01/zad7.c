// Calculating an integer of the function using Monte Carlo method

#define _XOPEN_SOURCE
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

const int eps = 1000000;

struct Point gen (struct Point a, struct Point b) {
    struct Point rand;
    rand.x = (b.x - a.x) * drand48() + a.x;
    rand.y = (b.y - a.y) * drand48() + a.y;
    return rand;
}

int main(void) {
    srand48(time(NULL));
    struct Point a, b, randomPoint;
    
    printf("Input the first point (x,y): ");
    scanf("%lf%lf", &a.x, &a.y);
    printf("Input the second point (x,y): ");
    scanf("%lf%lf", &b.x, &b.y);
    
    int ctr = 0;
    for (int i = 0; i < eps; i++) {
        randomPoint = gen(a,b);
        if (randomPoint.y < sin(randomPoint.x)) ctr++;
    }

    double area = (b.y-a.y)*(b.x-a.x);
    double div = (double)ctr/eps;
    printf("Pole kwadratu wynosi %lf\n", area);
    printf("Pole pod wykresem wynosi %lf\n", area*div);

    return 0;
}