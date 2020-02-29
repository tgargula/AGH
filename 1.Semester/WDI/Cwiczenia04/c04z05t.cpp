// Funkcja wypisuje nr wiersza i nr kolumny (licząc od 0), takie że iloraz: suma elementów w kolumnie przez suma elementów w wierszu jest największy (całkowite)
// #Można też rozbić na dwie funkcje (bez structa), ale chciałem sobie poćwiczyć

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 5, N = 100;    // N defines the interval of random numbers from -N to N

struct index {
    int i;
    int j;
};

index function (int t[MAX][MAX]) {
    double imin1, imin2, jmax1, jmax2, sum;
    index x,y;
    jmax1 = jmax2 = 0;
    imin1 = -MAX*N - 1;
    imin2 = MAX*N + 1;
    for(int i = 0; i < MAX; i++) {
        sum = 0;
        for(int j = 0; j < MAX; j++) sum += t[j][i];
        if(sum < 0 && sum > imin1) { imin1 = sum; x.i = i; }
        if(sum > 0 && sum < imin2) { imin2 = sum; y.i = i; }
    }

    for(int j = 0; j < MAX; j++) {
        sum = 0;
        for(int i = 0; i < MAX; i++) sum += t[j][i];
        if(sum < 0 && sum < jmax1) { jmax1 = sum; x.j = j; }
        if(sum > 0 && sum > jmax2) { jmax2 = sum; y.j = j; }
    }
    if(imin1 == -MAX*N-1 && imin2 == MAX*N+1) { x.i = -1; x.j = -1; return x; }
    if(imin1 == -MAX*N-1) return y;
    if(imin2 == MAX*N+1) return x;
    if(jmax1 / imin1 > jmax2 / imin2) return x; 
    return y;
}

int main() {
    int t[MAX][MAX];
    srand(time(NULL));
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            t[j][i] = rand() % (2*N + 1) - N;

    cout << "i \\ j\t\t";
    for(int i = 0; i < MAX; i++) cout << i << "\t";
    cout << endl << "\t";
    for(int i = 0; i <= MAX; i++) cout << "--------";
    cout << endl;
    for(int i = 0; i < MAX; i++) {
        cout << i << "\t|\t";
        for(int j = 0; j < MAX; j++) {
            cout << t[j][i] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
    // TEST - prints the matrix in a fancy form
    int a = function(t).i;
    int b = function(t).j;
    if(a > -1 && b > -1) {
        cout << "i\t" << a << endl;
        cout << "j\t" << b << endl;
    }
    else cout << "Such a pair does not exist" << endl;

    return 0;
}
