#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

struct complex {
    double re;
    double im;
};

void Input(complex &a, complex &b, complex &c) {
    cin >> a.re >> a.im >> b.re >> b.im >> c.re >> c.im;
    system("cls");
    cout << "(" << a.re << " + " << a.im << "i)x^2 + (" << b.re << " + " << b.im << "i)x + (" << c.re << " + " << c.im << "i) = 0" << endl;
}

complex Addition(complex a, complex b) {
    complex c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

complex Substraction(complex a, complex b) {
    complex c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}

complex Multiplication(complex a, complex b) {
    complex c;
    c.re = a.re*b.re - a.im*b.im;
    c.im = a.re*b.im + a.im*b.re;
    return c;
}

complex Division(complex a, complex b) {
    complex c;
    complex conjugate;
    conjugate.re = b.re;
    conjugate.im = -b.im;

    c = Multiplication(a, conjugate);
    c.re /= Multiplication(b, conjugate).re;
    c.im /= Multiplication(b, conjugate).re;
    return c;
}

complex DeltaSquare (complex a, complex b, complex c) {
    complex delta;
    delta = Multiplication(a,c);
    delta.re *= 4; delta.im *= 4;
    delta = Substraction(Multiplication(b,b),delta);
    return delta;
}

complex SquareRoot (complex a) {
    complex z;
    if(a.im == 0) {
        if(a.re == 0) return a;
        if(a.re < 0) {
            z.re = 0;
            z.im = sqrt(-a.re);
            return z;
        }
    }
    double absolute = sqrt(a.re*a.re + a.im*a.im);
    z.re = sqrt((absolute + a.re)/2);
    if(a.im < 0) z.re *= -1;
    z.im = -a.im / sqrt(2*(absolute + a.re));
    return z;
}

void Roots (complex a, complex b, complex &root1, complex &root2, complex delta) {
    a.re *= 2; a.im *= 2;
    b.re *= -1; b.im *= -1;
    root1 = Division(Addition(b, delta), a);
    root2 = Division(Substraction(b,delta),a);
}

void Output(complex a) {
    cout << a.re << " + " << a.im << "i" << endl;
}

int main() {
    complex a,b,c;
    Input(a,b,c);
    cout << "Delta^2 = "; Output(DeltaSquare(a,b,c));
    complex delta = SquareRoot(DeltaSquare(a,b,c));
    cout << "Delta = "; Output(delta);
    complex root1, root2;
    Roots(a,b,root1,root2,delta);

    cout << "Root1 = "; Output(root1);
    cout << "Root2 = "; Output(root2);

    return 0;
}
