#include <iostream>

using namespace std;

const int MAX = 10;

void spirala (int tab[MAX][MAX]) {
    int i = 0;
    int j = 0;
    int liczba = 1;
    int p = 0;

    while (true) {
        switch(p%4) {
            case 0: 
                while(i < MAX - j) tab[i++][j] = liczba++;
                i--;
                break;
            case 1:
                while(j <= i) tab[i][j++] = liczba++;
                j--;
                break;
            case 2:
                while(i >= MAX - j - 1) tab[i--][j] = liczba++;
                i++;
                break;
            case 3:
                while(j > i) tab[i][j--] = liczba++;
                j++;
                break;
        }
        if(liczba == MAX*MAX+1) break;
        liczba--;
        cout << endl;
        p++;
    }

    cout << "i \\ j\t\t";
    for(int i = 0; i < MAX; i++) cout << i << "\t";
    cout << endl << "\t";
    for(int i = 0; i <= MAX; i++) cout << "--------";
    cout << endl;
    for(int i = 0; i < MAX; i++) {
        cout << i << "\t|\t";
        for(int j = 0; j < MAX; j++) {
            cout << tab[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int tab[MAX][MAX];
    spirala(tab);

    return 0;
}
