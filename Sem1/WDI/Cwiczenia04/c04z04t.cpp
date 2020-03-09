// Funkcja wypisuje nr wiersza i nr kolumny (licząc od 0), takie że iloraz: suma elementów w kolumnie przez suma elementów w wierszu jest największy (naturalne)
// #Można też rozbić na dwie funkcje (bez structa), ale chciałem sobie poćwiczyć

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 15, N = 100;

struct index {
    int i;
    int j;
};

index function (int t[MAX][MAX]) {
    int imin, jmax, sum;
    index x;
    jmax = 0;
    imin = MAX*N;
    for(int i = 0; i < MAX; i++) {
        sum = 0;
        for(int j = 0; j < MAX; j++) sum += t[j][i];
        if(sum < imin) { imin = sum; x.i = i; }
    }

    for(int j = 0; j < MAX; j++) {
        sum = 0;
        for(int i = 0; i < MAX; i++) sum += t[j][i];
        if(sum > jmax) { jmax = sum; x.j = j; }
    }

    return x;
}

int main() {
    int t[MAX][MAX];
    srand(time(NULL));
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            t[j][i] = rand() % N + 1;

    // cout << "i \\ j\t\t";
    // for(int i = 0; i < MAX; i++) cout << i << "\t";
    // cout << endl << "\t";
    // for(int i = 0; i <= MAX; i++) cout << "--------";
    // cout << endl;
    // for(int i = 0; i < MAX; i++) {
    //     cout << i << "\t|\t";
    //     for(int j = 0; j < MAX; j++) {
    //         cout << t[j][i] << "\t";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    //
    // TEST - prints the matrix in a fancy form

    cout << "i\t" << function(t).i << endl;
    cout << "j\t" << function(t).j << endl;

    return 0;
}