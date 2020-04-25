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

bool isNotOK(int number) {
    int counter = 0;
    // cout << "OKisOK1" << endl;
    while(number > 0) {
        if(number % 2 == 1) {
            counter++;
        }
        number /= 2;
    } // cout << "OKisOK" << endl;
    if(counter % 2 == 1) return false;
    else return true;
}

bool isPossibleToRemove(int t[N][N]) {
    int tHelp[N] = {0};
    int max1 = 0, max2 = 0, ind1 = 0, ind2 = 0, howMuch = 0;
    for(int x = 0; x < N*N; x++) {
        if(isNotOK(t[x%N][x/N])) tHelp[x/N]++;
    }
    // cout << "OK1" << endl;
    for(int i = 0; i < N; i++) {
        if(t[i] != 0) {
            howMuch++;
            if(tHelp[i] > max1) {
                max2 = max1; max1 = tHelp[i];
                ind2 = ind1; ind1 = i;
            } else if(tHelp[i] > max2) {
                max2 = tHelp[i]; ind2 = i;
            }
        }
    }
    if(howMuch <= 2) return true;

    // cout << "OK2" << endl;
    for(int i = 0; i < N; i++) tHelp[i] = 0;
    howMuch = 0;

    for(int x = 0; x < N; x++) {
        for(int y = 0; y < N; y++) {
            if(y != ind1 and y != ind2) {
                if(isNotOK(t[x][y])) tHelp[x]++;
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(tHelp[i] != 0) howMuch++;
    }
    if(howMuch <= 1) return true;
    else return false;
}

int main() {
    int t[N][N];
    randomIntArray(t);
    printIntArray(t);
    if(isPossibleToRemove(t)) cout << "OK" << endl;
    return 0;
}