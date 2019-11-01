/*
11. Napisać program wyszukujący liczby zaprzyjaźnione mniejsze od miliona.

Niestety typowy brute
co to są liczby zaprzyjaźnione? https://pl.wikipedia.org/wiki/Liczby_zaprzyja%C5%BAnione#CITEREFGarc%C3%ADaPedersente_Riele2003

Program w tablicy divisors[1000000] za pomocą funkcji SumDivisors() sumuje podzielniki danej liczby i zapisuje je do divisors[1000000]
Odejmuje tą liczbę od sumy podzielników aby otrzymać porządaną sumę
Podzielniki liczby 0 zapisuje na miejscu i = 0, liczby 1 na i = 1, liczby 12 na i = 12 ...
W funckji Checker() program (metodą brute force) szuka par liczb zaprzyjaźnionych odrzucając liczby doskonałe
*/

#include<bits/stdc++.h>
using namespace std;

const int range = 1000000;
int divisors[range];

int SumDivisors(int number) {
    int sumDivisors = 0;
    for(int i = 1; i <= sqrt(number); i++) {
        if(number % i == 0) {
            sumDivisors += i + number / i;
        }
    }
    sumDivisors -= number;
    return sumDivisors;
}

void Checker() {
    for(int i = 1; i < range; i++) {
        for(int j = i; j < range; j++) {
            if(divisors[i] == j && divisors[j] == i && i != j) {
                cout << divisors[i] << " " << divisors[j] << endl;
            }
        }
    }
}

int main() {
    for(int i = 0; i < range; i++) {
        divisors[i] = SumDivisors(i);
    }

    // for(int i = 0; i < range; i++) {
    //     cout << divisors[i] << endl;
    // }

    Checker();
    return 0;
}