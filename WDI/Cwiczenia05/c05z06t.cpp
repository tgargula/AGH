#include <iostream>
#include <cstdlib>

using namespace std;

struct complex {
    double re;
    double im;
};

void Input(complex &a, complex &b) {
    cout << "a = ";
    cin >> a.re;
    system("cls"); cout << "a = " << a.re << " + ";
    cin >> a.im;
    system("cls"); cout << "a = " << a.re << " + " << a.im << "i" << endl << "b = ";
    cin >> b.re;
    system("cls"); cout << "a = " << a.re << " + " << a.im << "i" << endl << "b = " << b.re << " + ";
    cin >> b.im;
    system("cls"); cout << "a = " << a.re << " + " << a.im << "i" << endl << "b = " << b.re << " + " << b.im << "i\n\n";
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

complex Exponentation(complex a, int n) {
    complex temp = a;
    for(int i = 1; i < n; i++) a = Multiplication(a,temp);
    return a;
}

void Output(complex z) {
    cout << z.re << " + " << z.im << "i" << endl;
}

int main() {
    complex a,b;
    Input(a,b);
    cout << "a + b = "; Output(Addition(a,b));
    cout << "a - b = "; Output(Substraction(a,b));
    cout << "a * b = "; Output(Multiplication(a,b));
    cout << "a / b = "; Output(Division(a,b));
    int n;
    cout << endl << "Enter n: "; cin >> n;
    cout << "a^n = "; Output(Exponentation(a,n));
    cout << "b^n = "; Output(Exponentation(b,n));
}
