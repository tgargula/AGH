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
}

int GCD(int x, int y) {     // Greatest Common Divisor - NWD; Euclidean algorithm
    x = abs(x);
    while(x != y) {
        if(x > y) x -= y;
        else y -= x;
    }
    return x;
}

int LCD(int x, int y) {     // Lowest Common denominator - NWW
    return x*y/GCD(x,y);
}

void CancelingDown (rational &a) {
    if(a.num == 0) a.den = 1;
    else {
        int d = GCD(a.num, a.den);
        a.num /= d;
        a.den /= d;
    }
}

void Output(rational a) {
    cout << a.num << "/" << a.den << endl;
}

rational Addition (rational a, rational b) {
    rational c;
    c.den = LCD(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num + b.num;
    CancelingDown(c);
    return c;
}

rational Substraction (rational a, rational b) {
    rational c;
    c.den = LCD(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num - b.num;
    CancelingDown(c);
    return c;
}

rational Multiplication (rational a, rational b) {
    rational c;
    CancelingDown(a); CancelingDown(b);
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    CancelingDown(c);
    return c;
}

rational Division (rational a, rational b) {
    rational c;
    CancelingDown(a); CancelingDown(b);
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    CancelingDown(c);
    return c;
}

rational Exponentation (rational a, int n) {
    CancelingDown(a);
    int temp1 = a.num;
    int temp2 = a.den;
    for(int i = 1; i < n; i++) {
        a.num *= temp1;
        a.den *= temp2;
    }
    return a;
}

void Menu() {
    cout << "\nSelect what you want to do:\n";
    cout << "\t1. Addition\n";
    cout << "\t2. Substraction\n";
    cout << "\t3. Multiplication\n";
    cout << "\t4. Division\n";
    cout << "\t5. Exponentation\n";
    getchar();
}


int main() {
    rational a, b;
    char option;

    Input(a,b);
    Menu();
    option = getchar();
    system("cls");

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

    return 0;
}
