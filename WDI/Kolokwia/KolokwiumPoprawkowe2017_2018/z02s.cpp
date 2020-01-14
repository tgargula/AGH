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

int function(int t1[N], int t2[N], int sum1, int sum2, int ile = N, int p1 = 0, int p2 = 0) {
    if(sum1 == sum2) return ile;
    if(p1==N || p2==N) return 0;
    int m = 0;
    for(int i = p1; i < N; i++) {
        for(int j = p2; j < N; j++) {
            m = max(function (t1, t2, sum1,sum2,ile, i+1, j+1), function(t1,t2,sum1-t1[i], sum2-t2[j],--ile,i+1,j+1));
            if(m>0) return m;
        }
    }
    return 0;
}

int function2(int t1[N], int t2[N]) {
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i < N; i++) {
        sum1+=t1[i];
        sum2+=t2[i];
    }
    return function(t1,t2,sum1,sum2);
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
   // cout << returnMaxN(t1, t2) << endl;
   t2[4] = 1;
   t2[3] = 8;
   t2[2] = 3;
   cout << function2(t1,t2) << "\n";
    return 0;
}