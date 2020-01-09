#include <iostream>
#include <cstdlib>
#include <stdio.h>

using namespace std;

struct rational {
    int num;    // numerator (licznik)
    int den;    // denominator (mianownik)
};

void Input(rational &a, rational &b) {          // We can also change this function so that it loads rational numbers in the form of "a/b"
    cout << "First rational number" << endl;
    cout << "\tEnter a numerator: "; cin >> a.num;
    cout << "\tEnter a denominator: "; cin >> a.den;
    cout << "Second rational number" << endl;
    cout << "\tEnter a numerator: "; cin >> b.num;
    cout << "\tEnter a denominator: "; cin >> b.den;
    system("cls");
    cout << "a = " << a.num << "/" << a.den << "\nb = " << b.num << "/" << b.den << endl;
}

/*
void Input2(rational &a, rational &b) {
    double n, m;
    int temp;
    cin >> n >> m;
    //temp = floor(n);
    a.num = 0;
    for(int i = 1; i < 6; i++) {
        n *= 10;
        a.num += n % 10;
        a.num *= 10;
    }
    cout << a.num;
}
*/

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

int LCD(int x, int y) {     // Lowest Common Denominator - NWW
    return x*y/GCD(x,y);
}

void CancellingDown (rational &a) {
    if(a.num == 0) a.den = 1;
    else {
        int d = GCD(a.num, a.den);
        a.num /= d;
        a.den /= d;
    }
}

void Output(rational a) {
    if(a.den == 1) cout << a.num << endl;
    else cout << a.num << "/" << a.den << endl;
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
    CancellingDown(c);
    return c;
}

rational Substraction (rational a, rational b) {
    rational c;
    c.den = LCD(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num - b.num;
    CancellingDown(c);
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
    int temp1 = a.num;
    int temp2 = a.den;
    for(int i = 1; i < n; i++) {
        a.num *= temp1;
        a.den *= temp2;
    }
    return a;
}

/*
void Menu() {
    cout << "\nSelect what you want to do:\n";
    cout << "\t1. Addition\n";
    cout << "\t2. Substraction\n";
    cout << "\t3. Multiplication\n";
    cout << "\t4. Division\n";
    cout << "\t5. Exponentation\n";
    getchar();
}
*/

int main() {
    rational a, b;
    char option;
    //Input2(a,b);
    Input(a,b);
    // Menu();
    // option = getchar();
    // system("cls");

    /*
    switch(option){
        case '1':
            Output(Addition(a,b));
            break;
        case '2':
            Output(Substraction(a,b));
            break;
        case '3':
            Output(Multiplication(a,b));
            break;
        case '4':
            Output(Division(a,b));
            break;
        case '5':
            int n;
            cin >> n;
            Output(Exponentation(a,n));
            break;
        default:
            cout << "Such an option does not exist";
            break;
    }
    */
    cout << endl;
    cout << "a+b = "; Output2(Addition(a,b));
    cout << "a-b = "; Output2(Substraction(a,b));
    cout << "a*b = "; Output2(Multiplication(a,b));
    cout << "a/b = ";
    if(b.num == 0) cout << "You cannot divide by 0\n";
    else Output2(Division(a,b));

    int n;
    cout << "\nEnter n: ";
    cin >> n;
    cout << "a^n = "; Output2(Exponentation(a,n));
    cout << "b^n = "; Output2(Exponentation(b,n));

    return 0;
}
