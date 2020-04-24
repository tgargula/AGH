#include <iostream>

using namespace std;

const int N = 8;

void RandomArray(int tab[N][N]) {
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            srand(rand());
            tab[i][j] = rand() % 100;
            cout << tab[i][j] << '\t';
        }
        cout << '\n';
    }
}

int PierwszaCyfra(int t[N][N], int wiersz, int kolumna) {
    int n = t[wiersz][kolumna], pierwsza;
    // cout << "pierwsza " << n << endl;
    while(n > 0) {
        pierwsza = n % 10;
        n /= 10;
    }
    return pierwsza;
}

bool CzyMozliwyRuch(int wiersz, int kolumna, int ostatniaCyfra, int t[N][N]) {
    // cout << "CzyMozliwyRuch" << endl;
    cout << "docelowe: wiersz " << wiersz << " kolumna " << kolumna << endl; 
    // cout << "ostatniaCyfra " << ostatniaCyfra << endl;
    // cout << "pierwszaCyfra " << PierwszaCyfra(t, wiersz, kolumna) << endl;
    if(wiersz < 0 or wiersz > N-1 or kolumna < 0 or kolumna > N-1 or ostatniaCyfra >= PierwszaCyfra(t, wiersz, kolumna)) {
        cout << "CzyMozliwyRuch false" << endl; return false;
    } 
    return true;
}

bool CzyMozliweDojscie(int t[N][N], int wiersz, int kolumna, bool &flag) {
    cout << "start " << endl;
    cout << "wiersz " << wiersz << " kolumna " << kolumna << endl;
    if(wiersz == N-1 and kolumna == N-1) {
        cout << "true" << endl;
        flag = false;
        return true;
    }
    for(int i = 0; i < 3 and flag; i++) {
        if(i == 0) {
            if(CzyMozliwyRuch(wiersz+1, kolumna+1, t[wiersz][kolumna] %10, t)) {
                cout << "case 0" << endl; CzyMozliweDojscie(t, wiersz+1, kolumna+1, flag); 
            }
        } else if(i == 1) {
            if(CzyMozliwyRuch(wiersz+1, kolumna, t[wiersz][kolumna] %10, t)) {
                cout << "case 1" << endl; CzyMozliweDojscie(t, wiersz+1, kolumna, flag); 
            }
        } else {
            if(CzyMozliwyRuch(wiersz, kolumna+1, t[wiersz][kolumna] %10, t)) {
                cout << "case 2" << endl; CzyMozliweDojscie(t, wiersz, kolumna+1, flag); 
            }
        }      
    }
    if(flag == false) {
        return true;
    } else return false;
}

int main () {
    static int t[N][N];
    RandomArray(t);
    int startWiersz, startKolumna; bool flag = true;
    cin >> startWiersz >> startKolumna;
    if(CzyMozliweDojscie(t, startWiersz, startKolumna, flag)) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
    return 0;
}