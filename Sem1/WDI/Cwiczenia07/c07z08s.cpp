#include <iostream>
#include <algorithm>

using namespace std;

const int N = 4;
int tab[N][N];

void RandomArray() {
    //srand(time(NULL)); 
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            srand(rand());
            tab[i][j] = rand() % 10;
            cout << tab[i][j] << '\t';
        }
        cout << '\n';
    }
}

bool Mozliwosc(int kolumna) {
    //cout << "Mozliwosc" << endl;
    if(kolumna < 0 or kolumna  > N-1) return false;
    return true;
}

int SpacerKrola(int t[N][N], int kolumna, int suma, int wiersz, int &sumaMin) {
    // cout << "wiersz " << wiersz << endl;
    // cout << "kolumna " << kolumna << endl;
    // cout << "pozycja " << tab[wiersz][kolumna] << endl;
    suma += tab[wiersz][kolumna];
    // cout << "suma " << suma << endl;
    if(wiersz == N-1) {
        sumaMin = min(sumaMin, suma);
        // cout << "sumaMin " << sumaMin << '\n' << endl;
        return suma;
    } 
    for(int i = 0; i < 3; i++) {
        if(Mozliwosc(kolumna-1 +i)) {
            SpacerKrola(t, kolumna-1+i, suma, wiersz+1, sumaMin);
        }
    }
    return sumaMin;
}

int main () {
    RandomArray();
    int kolumnaStart, sumaMin = 93242; cin >> kolumnaStart;
    cout << SpacerKrola(tab, kolumnaStart, 0, 0, sumaMin) << endl;
    return 0;
}