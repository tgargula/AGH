#include <bits/stdc++.h>

using namespace std;

const int N = 10000;
const int MAX = 10;

struct rat {
    int num;
    int den;
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

int LCD(int x, int y) {     // Lowest Common Denominator - NWW
    return x*y/GCD(x,y);
}

void CancellingDown (rat &a) {
    if(a.num == 0) a.den = 1;
    else {
        int d = GCD(a.num, a.den);
        a.num /= d;
        a.den /= d;
    }
}

rat Addition (rat a, rat b) {
    rat c;
    c.den = LCD(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num + b.num;
    CancellingDown(c);
    return c;
}

rat Substraction (rat a, rat b) {
    rat c;
    c.den = LCD(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num - b.num;
    CancellingDown(c);
    return c;
}

rat Multiplication (rat a, rat b) {
    rat c;
    CancellingDown(a); CancellingDown(b);
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    CancellingDown(c);
    return c;
}

rat Division (rat a, rat b) {
    rat c;
    CancellingDown(a); CancellingDown(b);
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    CancellingDown(c);
    return c;
}

int FUNCTION (rat t[N]) {
    int LA, LG; LA = LG = 0;
    rat r, q;
    bool b;
    for(int i = 1; i < N-1; i++) {
        b = false;
        r = Substraction(t[i],t[i-1]);
        while(t[i+1].num == Addition(t[i],r).num && t[i+1].den == Addition(t[i],r).den) {
            i++;
            b = true;
        }
        if(b) LA++;
    }

    for(int i = 1; i < N-1; i++) {
        b = false;
        if(t[i-1].num != 0) q = Division(t[i],t[i-1]);
        else continue;
        while(t[i+1].num == Multiplication(t[i],q).num && t[i+1].den == Multiplication(t[i],q).den) {
            i++;
            b = true;
        }
        if(b) LG++;
    }
    cout << LG << " " << LA << endl;
    if(LG > LA) return -1;
    if(LG < LA) return 1;
    return 0;
}

int main() {
    rat t[N];
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        srand(rand());
        t[i].num = rand() % (2*MAX + 1) - MAX;
        t[i].den = rand() % MAX + 1;
        CancellingDown(t[i]);
        //cout << t[i].num << "/" << t[i].den << " ";
    }

    /*for(int i=0; i < N; i++) {
        cin >> t[i].num >> t[i].den;
        CancellingDown(t[i]);
    }
    //system("cls");
    //for(int i=0; i < N; i++) cout << t[i].num << "/" << t[i].den << " ";*/

    cout << FUNCTION(t) << endl;




    return 0;
}
