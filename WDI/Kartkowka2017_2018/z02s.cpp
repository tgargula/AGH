#include <iostream>

using namespace std;

const int N = 1000;
int tab[N];

void WypelnijTablice() {
    for(int i =0; i < N; i ++) {
        tab[i] = i;
    }
}

int WyznaczKoniec(int &koniec){
    while(koniec < N) {
        if(tab[koniec+1] < tab[koniec])return koniec;
        koniec++;
    }
    return koniec;
}

bool Sumy(int start, int koniec) {
    
}

int ZnajdzNajdluzszy() {
    int start, koniec, najdluzszy = 0;
    start = koniec = najdluzszy;
    while(koniec < N) {
        for(int i = 0; i < N; i++) {
            if(tab[i] < tab[i+1]) {
                start = i; koniec = i + 1;
            }
        }
        WyznaczKoniec(koniec);
        if(koniec - start > najdluzszy) {

        }     
    }
}

int main() {
    WypelnijTablice();

}