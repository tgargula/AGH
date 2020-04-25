#include <iostream>
#include "classes.hpp"

using namespace std;

int main() {
    Complex complex1, complex2;
    complex1.set(5,-6.7);
    complex1.output();
    complex2.set(3.4,-7);
    complex2.output();

    complex1.add(complex2).output();
    complex1.substract(complex2).output();
    complex1.multiply(complex2).output();
    complex1.divide(complex2).output();

    Rational x;

    x.set(2,7);
    x.output();
    x.output();
    x.outputAsFraction();

    return 0;
}