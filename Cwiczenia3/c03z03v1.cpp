/*
3. Napisać program generujący i wypisujący liczby pierwsze mniejsze od N metodą Sita Eratostenesa

https://pl.wikipedia.org/wiki/Sito_Eratostenesa

tak zeby sie nie pomylic biore tez 0 do rozwazan w tablicy

walker - spacerowicz po tablicy; start - nowy punkt startowy dla spacerowicza po pokonaniu zakresu
zmiana wartosci na false = wykreslenie z tablicy
*/


//////////////////NIE DZIALA!!!!!!!!!!
#include<bits/stdc++.h>
using namespace std;

const int N = 100;

main() {
    bool Numbers[N] = {true};
    Numbers[0] = false; Numbers[1] = false;
    int walker = 2, start = 2;

    while(start < N) {
        while(Numbers[start] == false) {
            start++; cout << "hurr durr " << start << endl;
            walker = start; cout << "start 1" << endl;
            while(walker + start < N) {
                walker = walker + start; Numbers[walker] = false; cout << walker <<endl;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(Numbers[i]) cout << i;
    }
    return 0;
}