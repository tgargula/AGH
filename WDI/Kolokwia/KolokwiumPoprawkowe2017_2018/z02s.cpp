#include <iostream>
#include <time.h>
#include <cstdlib>
// #include "functions.hpp"

using namespace std;

const int N = 5;

void RandomIntArray(int Array[], int arraySize, int range = 100) {
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
        srand(rand());
        Array[i] = rand() % range; 
    }
}

void PrintIntArray(int Array[], int arraySize) {
    for(int i = 0; i < N; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

bool returnMaxRecursion(int t1[N], int t2[N], int &maxN, int sumN, int n1, int n2, int sum) {
    if(n1 == N or n2 == N) return false;
    if(sum == 0) maxN = max(maxN, sumN);
    while(n1 < N) {
        while(n2 < N) {
            cout << "while" << endl;
            return returnMaxRecursion(t1, t2, maxN, sumN+1, n1+1, n2+1, sum+t1[n1+1]-t2[n2+1]) or returnMaxRecursion(t1, t2, maxN, sumN, n1+1, n2+1, sum);
        }
    }
}

int returnMaxN(int t1[N], int t2[N]) {
    int maxN = 0, sumN = 1, sum = 0;
    returnMaxRecursion(t1, t2, maxN, sumN, 0, 0, 0);
    return maxN;
}

int main() {
    int t1[N]; int t2[N];
    RandomIntArray(t1, N); PrintIntArray(t1, N);
    RandomIntArray(t2, N); PrintIntArray(t2, N);
    cout << returnMaxN(t1, t2) << endl;
    return 0;
}