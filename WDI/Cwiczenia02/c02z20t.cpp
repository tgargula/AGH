// Program wyznacza przybliżony pierwiastek równania: x^x = 2017 metodą stycznych
// Metoda Newtona (stycznych): https://pl.wikipedia.org/wiki/Metoda_Newtona

#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-6;

double f(double x) { return pow(x,x)-2017; }

double df(double x) { return pow(x,x)*(log(x)+1); }

double approximation (double x1, double x2) {
    if(abs(x2 - x1) < eps) return x1;
    return approximation (x2, x2 - f(x2)/df(x2)); 
}

int main() {
    double x1, x2;
    x1 = 4.5; x2 = x1 - f(x1) / df(x1);
    cout << approximation(x1,x2) << endl;

    return 0;
}