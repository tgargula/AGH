/*
2.Dana jest tablica int t[MAX][MAX]wypełniona liczbami naturalnymi.
Proszę napisać funkcję który odpowiada na pytanie, czy w każdym wierszu tablicy występuje co najmniej jedna liczba złożona wyłącznie z nieparzystych cyfr.

UMOWNIE - pierwszay parametr [i] wskazuje nr wiersza, drugi [j] wskazuje nr kolumny
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 5000;
int tab[MAX][MAX];

bool ifOdd(int n) {        //true - cała liczba z cyfr nieparzystych
    while(n > 0) {
        if(n % 2 == 0) return false;
        n /= 10;
    }
    return true;
}

int Checker() {
    bool Not = true; //Not = true - w wierszu nie ma żadnych pożądanych liczb;

    for(int i = 0; i < MAX; i++) {
        Not = true;
        for(int j = 0; j < MAX; j++, Not) {
            if(ifOdd(tab[i][j])) {
                Not = false;
            }
        }
        if(Not) {
            cout << "NIE"; return 0;
        }
    }
    cout << "TAK";
    return 0;
}

void RandomArray() {
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            srand(rand());
            tab[i][j] = rand() % 100000;
        }
    }
}

int main() {
    RandomArray();
    // for(int i = 0; i < MAX; i++) {       TEST - wypisz tablicę
    //     for(int j = 0; j < MAX; j++) {
    //         cout << tab[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    Checker();
    return 0;
}