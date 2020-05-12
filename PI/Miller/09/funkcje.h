#include <math.h>

double funkcja1(double x) {
    return 1.0 / ((x - 0.5) * (x - 0.5) + 0.01);
}

double funkcja2(double x) {
    return sin(x);
}

double funkcja3(double x) {
    return x*x*x*x;
}