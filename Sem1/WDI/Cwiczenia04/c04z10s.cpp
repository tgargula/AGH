/*
10.Napisać funkcję która dla tablicy typu int t[MAX][MAX],wypełnionej liczbami całkowitymi, zwraca wartość true w przypadku, gdy w każdym wierszu i każdej 
kolumnie występuje conajmniej jedno 0 oraz wartość false w przeciwnym przypadku.
*/

#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;
int t[MAX][MAX];

void RandomArray() {
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            t[i][j] = rand() % 100;
            if(rand() % 7 == 0) t[i][j] = 0;
        }
    }
}

void PrinterT() {              //helper wypisz t
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

bool FindZero() {
    bool temp[MAX];             //ta tablica sprawdza czy w każdej kolumnie znajdują się zera żeby po całej tablicy trzeba było przechodzić tylko 1 raz
    for(int i = 0; i < MAX; i++) {
        temp[i] = true;
    }   

    for(int i = 0; i < MAX; i++) {
        bool flag = true;
        for(int j = 0; j < MAX; j++) {
            if(t[i][j] == 0) {
                flag = false;
                temp[i] = flag;
            }
        }
        if(flag) return false;
    }

    for(int i = 0; i < MAX; i++) {
        if(temp[i]) return false;
    }

    return true;
}

int main() {
    RandomArray();
    PrinterT();
    if(FindZero()) cout << "OK";
    else cout << "NOT";

    return 0;
}
