#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

struct rational {
    int num;    // numerator (licznik)
    int den;    // denominator (mianownik)
};

int GCD(int x, int y) {     // Greatest Common Divisor - NWD; Euclidean algorithm
    x = abs(x);
    if(x < y) swap(x,y);
    int temp;
    while(x%y != 0) {
        temp = x;
        x = y;
        y = temp % y;
    }
    return y;
}

int LCD(int x, int y) {     // Lowest Common denominator - NWW
    return x*y/GCD(x,y);
}

void CancellingDown(rational &a) {
    int d = GCD(a.num, a.den);
    a.num /= d;
    a.den /= d;
}

void Output(rational a) {
    if(a.den < 0) { a.num *= -1; a.den *= -1; }
    if(a.den == 1) cout << a.num;
    else cout << a.num << "/" << a.den;
}

int max25 (int b) {     // Bêdzie tyle miejsc po przecinku nie w okresie, ile wynosi najwiêksza potêga 2 lub 5
    int i2, i5, t;
    i2 = i5 = 0;
    t = b;
    while(t % 2 == 0) {
        i2++;
        t /= 2;
    }
    t = b;
    while(t % 5 == 0) {
        i5++;
        t /= 5;
    }
    return max(i2, i5);
}

void Output2(rational a) {
    int m = max25(a.den);
    if(a.num < 0 && a.den < 0) { a.num = abs(a.num); a.den = abs(a.den); }
    if(a.num < 0 || a.den < 0) { cout << "-"; a.num = abs(a.num); a.den = abs(a.den); }
    int t = a.num%a.den;
    cout << a.num/a.den;
    if(a.num % a.den != 0) {
        cout << ".";
        for(int i = 0; i < m; i++) {
            t %= a.den;
            t *= 10;
            cout << t/a.den;
        }
        if(t % a.den != 0) {
            int r = t%a.den;
            cout << "(";
            do {
                t %= a.den;
                t *= 10;
                cout << t/a.den;
            }   while(r != t%a.den);
            cout << ")";
        }
    }
    cout << endl;
}

rational Addition (rational a, rational b) {
    rational c;
    c.den = LCD(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num + b.num;
    return c;
}

rational Substraction (rational a, rational b) {
    rational c;
    c.den = LCD(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num - b.num;
    return c;
}

rational Multiplication (rational a, rational b) {
    rational c;
    CancellingDown(a); CancellingDown(b);
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    CancellingDown(c);
    return c;
}

rational Division (rational a, rational b) {
    rational c;
    CancellingDown(a); CancellingDown(b);
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    CancellingDown(c);
    return c;
}

rational Exponentation (rational a, int n) {
    CancellingDown(a);
    a.num *= n;
    a.den *= n;
}

void Input(rational &a, rational &b, rational &c, rational &d, rational &e, rational &f) {
    cin >> a.num >> a.den;
    cin >> b.num >> b.den;
    cin >> c.num >> c.den;
    cin >> d.num >> d.den;
    cin >> e.num >> e.den;
    cin >> f.num >> f.den;
    CancellingDown(a); CancellingDown(b); CancellingDown(c); CancellingDown(d); CancellingDown(e); CancellingDown(f);
    system("cls");
    cout << "("; Output(a); cout << ")*x + ("; Output(b); cout << ")*y = "; Output(c); cout << endl;
    cout << "("; Output(d); cout << ")*x + ("; Output(e); cout << ")*y = "; Output(f); cout << endl;
    cout << "\n\n";
}

int main() {
    rational a, b, c, d, e, f;
    // ax + by = c
    // dx + ey = f

    Input(a,b,c,d,e,f);

    rational W, Wx, Wy;
    W = Substraction(Multiplication(a,e),Multiplication(b,d));
    Wx = Substraction(Multiplication(c,e),Multiplication(b,f));
    Wy = Substraction(Multiplication(a,f),Multiplication(c,d));
    if(W.num == 0) {
        if(Wx.num == 0 && Wy.num == 0) cout << "That is undetermined system with an infinite number of solutions\n";
        else cout << "That is undetermined system with no solutions\n";
    }
    else {
        rational x, y;
        x = Division(Wx,W);
        y = Division(Wy,W);
        cout << "x = "; Output(x); cout << "\nx = "; Output2(x);
        cout << "\ny = "; Output(y); cout << "\ny = "; Output2(y);
    }
    return 0;
}
