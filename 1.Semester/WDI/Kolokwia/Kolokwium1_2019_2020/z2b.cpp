#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 10;

void randomIntArray(int t[N][N]) {
    srand(time(NULL));
    for(int x = 0; x < N*N; x++) {
        srand(rand());
        t[x/N][x%N] = rand() % 2;
        // t[x/N][x%N] = 1;
    }
}

void printIntArray(int t[N][N]) {
    for(int x = 0; x < N*N; x++) {
        cout << t[x/N][x%N] << " ";
        if(x%N == N-1) cout << endl;
    }
}

int main() {
    int t[N][N];
    randomIntArray(t);
    printIntArray(t);
    
    return 0;
}