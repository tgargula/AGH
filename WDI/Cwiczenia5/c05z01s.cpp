/*
1. Liczby wymierne są reprezentowane przez strukturę:
struct ulamek {
    int l; // licznik –liczba całkowita
    int m; // mianownik –liczba większa od 0
    };
Proszę napisać podstawowe operacje na ułamkach, m.in. dodawanie, odejmowanie, mnożenie, dzielenie, potęgowanie, skracanie, wypisywanie i wczytywanie.
*/

#include<bits/stdc++.h>
using namespace std;

struct ulamek {
    int l;
    int m;
};

int NWD(int a, int b) {
    a = abs(a); b = abs(b);
    if(a == 0 || b == 0) return 1;
    if(a == b) return a;
    while(a != b)
       if(a > b)
           a -= b;
       else
           b -= a;

    return a;
}

ulamek Skracanie(ulamek u) {
    int a = NWD(u.l, u.m);
    u.l /= a;
    u.m /= a;

    return u;
}

ulamek Dodawanie(ulamek a, ulamek b) {
    ulamek wynik;
    wynik.m = a.m * b.m;
    a.l *= b.m; b.l *= a.m;
    wynik.l = a.l + b.l;
    wynik = Skracanie(wynik);
    return wynik;
}

ulamek Odejmowanie(ulamek a, ulamek b) {
    ulamek wynik;
    b.l *= -1;
    wynik = Dodawanie(a, b);
    return wynik;
}

ulamek Mnozenie(ulamek a, ulamek b) {
    ulamek wynik;
    wynik.l = a.l * b.l;
    wynik.m = a.m * b.m;
    wynik = Skracanie(wynik);
    return wynik;
}

ulamek Dzielenie(ulamek a, ulamek b) {
    ulamek wynik;
    int m = b.m;
    b.m = b.l; b.l = m;
    wynik = Mnozenie(a, b);
    return wynik;
}

ulamek Potegowanie(ulamek a, int wykladnik) {
    ulamek wynik; wynik.l = wynik.m = 1;
    for(wykladnik; wykladnik > 0; wykladnik--) {
        wynik.l = wynik.l * a.l;
        wynik.m = wynik.m * a.m;
    }
    return wynik;
}

ulamek Wczytywanie() {
    ulamek u; bool flag = true;
    while(flag) {
        cin >> u.l >> u.m;
        if(u.m == 0) {cout << "mianownik = 0 - to nie ulamek";} 
        else flag = false;
    }
    return u;
}

void Wypisywanie(ulamek u) {
    cout << u.l << "/" << u.m << endl;
}

double Ulamek10tny(ulamek a) {
    float wynik, l = a.l, m = a.m;
    wynik = l/m; 
    return wynik;
}

ulamek LosowyUlamek() {
    ulamek u;
    u.l = rand() % 1000;
    srand(rand()); 
    u.m = rand() % 998 + 1;
    return u;
}

int main() {
    ulamek a, b, u; double wynik;
    a.l = -1; a.m = 2; b.l = -2; b.m = 4;

    // u.l = 102; u.m = 50;
    // Wypisywanie(Skracanie(u));

    srand(time(NULL)); a = LosowyUlamek(); b = LosowyUlamek();
    cout << "a = " ; Wypisywanie(a);
    cout << "b = " ; Wypisywanie(b);

    Wypisywanie(Dodawanie(a, b));
    Wypisywanie(Odejmowanie(a, b));
    Wypisywanie(Mnozenie(a, b));
    Wypisywanie(Dzielenie(a, b));
    Wypisywanie(Potegowanie(b, 3));
    wynik = Ulamek10tny(a); cout << "~" << wynik << endl;
}