/*
6.Proszę napisać program, który wczytuje wprowadzany z klawiatury ciąg liczb naturalnych zakończonych zerem 
stanowiącym wyłącznie znacznik końca danych.  
Program powinien wypisać 10 co do wielkości wartość, 
jaka wystąpiła w ciągu.  Można założyć, że w ciągu znajduje się wystarczająca liczba elementów


program wykorzystuje długi czas wprowadzania danych przez użytkownika dzięki czemu złożoność czasowa obliczeń wynosi 1 obieg pętli 10 elementowej
*/

#include<bits/stdc++.h>
using namespace std;

int Max10th() {
    int n; int tab[10];
    for(int i = 0; i < 10; i++) tab[i] = 0;
    do {
        cin >> n;
        for(int i = 0; i < 10; i++) {
            if(n > tab[i]) {
                for(int j = 9; j > i; j--) {
                    tab[j] = tab[j-1];
                }
                tab[i] = n; i = 10;
            }
        }
        // for(int i = 0; i < 10; i++) cout << tab[i] << " ";       TEST
        // cout << '\n';
    } while (n != 0);
    return tab[9];
}


int main() {
    int max = Max10th();
    cout << max << endl; return 0;
}