// Funkcja sprawdza, czy w tablicy każdy wiersz posiada co najmniej jedną liczbę złożoną z cyfr będących liczbami pierwszymi

#include <iostream>

using namespace std;

const int MAX = 10;

void RandomArray(int t[MAX][MAX]) {
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) 
        for(int j = 0; j < MAX; j++) t[i][j] = rand() % 100 + 1;
}

void PrintMatrix(int t[MAX][MAX]) {
    cout << "i \\ j\t\t";
    for(int i = 0; i < MAX; i++) cout << i << "\t";
    cout << endl << "\t";
    for(int i = 0; i <= MAX; i++) cout << "--------";
    cout << endl;
    for(int i = 0; i < MAX; i++) {
        cout << i << "\t|\t";
        for(int j = 0; j < MAX; j++) {
            cout << t[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool PrimeDigits (int n) {
    int r;
    while(n > 0) {
        r = n % 10;
        if(!(r == 2 or r == 3 or r == 5 or r == 7)) return false;
        n /= 10;
    }
    return true;
}

bool FUNCTION (int tab[MAX][MAX]) {
    for(int i = 0; i < MAX; i++) {
        bool b = false;
        for(int j = 0; j < MAX and !b; j++) if(PrimeDigits(tab[i][j])) b = true;
        if(!b) return false;
    }
    return true;
}

int main() {
    int t[MAX][MAX];
    RandomArray(t);
    PrintMatrix(t);

    if(FUNCTION(t)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}