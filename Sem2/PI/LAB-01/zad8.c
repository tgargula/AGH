#include <stdio.h>
#include <math.h>

inline double abs (double x) { return x > 0 ? x : -x; }

inline short sign (int x) { return x % 4 == 0 ? 1 : -1; }

double factorial (int x) {
    long long res = 1;
    for (int i = 2; i <= x; i++) res *= i;
    return res;
}

double taylorApproximationOfCos (double x) {
    double res = 1;
    double eps = 1e-6;
    double summand;
    int i = 2;
    do {
        summand = sign(i) * pow(x,i) / factorial(i);
        res += summand;
        i+=2;
    } while (abs(summand) > eps);
    return res;
}

int main(void) {
    double start, end, step;
    printf("Input start: ");
    scanf("%lf", &start);
    printf("Input end: ");
    scanf("%lf", &end);
    printf("Input step: ");
    scanf("%lf", &step);
    for (double x = start; x < end; x += step) {
        printf("%lf\t%lf\t%lf\n", x, cos(x), taylorApproximationOfCos(x));
    }

    return 0;
}