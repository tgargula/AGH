/*
10.Napisać program wyszukujący liczby doskonałe mniejsze od miliona.

Liczba doskonała - suma jej podzielników mniejszych od niej samej jest jej równa

METODA BRUTE  -  DŁUŻEJ NIŻ REKLAMY NA POLSAT
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int sum;
    for(int i = 2; i < 1000000; i += 2) {
        //int i = 6; 
        sum = 0;
        for(int j = 1; j <= i / 2; j ++) {
            if(i % j == 0) {
                sum = sum + j; cout << "l " << sum << endl;
            }
        }
        if(sum == i) cout << i << endl;
    }
    return 0;
}