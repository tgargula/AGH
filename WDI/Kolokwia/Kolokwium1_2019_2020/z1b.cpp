#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>
// #include "functions.hpp"

using namespace std;

const int N = 30;

void RandomIntArray(int Array[], int range = 100) {
    srand(time(NULL)); 
    for(int i = 0; i < N; i++) {
        srand(rand());
        Array[i] = rand() % range;
    }
}

void PrintIntArray(int Array[]) {
    for(int i = 0; i < N; i++) {
        cout << Array[i] << " ";
    }
}

int main() {
    int t1[N], t2[N];
    RandomIntArray(t1, 10); RandomIntArray(t2, 10);
    
    return 0;
}