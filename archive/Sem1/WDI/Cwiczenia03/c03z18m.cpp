/*
18.Funkcja wyznacza różnicę pomiędzy wartością maksymalną a minimalną. Ile minimalnie porównań trzeba wykonać?
*/

#include<bits/stdc++.h>

using namespace std;

const int N=10;

void Difference(int tab[], int MIN, int MAX) {
    for(int i = 0; i < N; i++){
        if(tab[i] < MIN) MIN=tab[i];
        else if(tab[i] > MAX) MAX=tab[i];
    }

    cout<<MAX-MIN<<endl;
}

int main(){
    int tab[N];
    int MAX = 0, MIN = 2147483647;

    srand(time(NULL));

    for(int i = 0; i < N; i++) {
        srand(rand());
        tab[i] = rand() % 12;
    }

    Difference(tab, MIN, MAX);

    for(int i = 0; i < N; i++) {
        cout << tab[i] << " ";
    }

    cout << '\n' << "2N-1 Panie Garku" << endl;
    return 0;
}