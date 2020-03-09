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


bool isSumOK(int sum) {
    for(int b = 2; b*b <= sum; b++) {
        for(int e = 2; pow(b, e) <= sum; e++) {
            if(pow(b, e) == sum) return true;
        }
    }
    return false;
}

int Sum(int t[N], int istart, int il) {
    int sum = 0;
    for(int i = istart; i < istart + il; i++) {
        sum += t[i];
    }
    // cout << "sum " << sum << endl;
    return sum;
}

bool chooseArrayParts(int t1[N], int t2[N]) {
    for(int i1 = 0; i1 < N and i1 < 24; i1++) {
        int i2 = 24 - i1; int i1start = 0, i2start = 0;

        while(i1start + i1 < N) {
            i2start = 0;
            while(i2start + i2 < N) {
                // cout << "i1 " << i1 << " i2 " << i2 << endl;
                // cout << "i1s " << i1start << " i2s " << i2start << endl;
                if(isSumOK(Sum(t1, i1start, i1) + Sum(t2, i2start, i2))) return true;
                i2start++;
            }
            i1start++;
        }
    }
    return false;
}

int main() {
    int t1[N], t2[N];
    RandomIntArray(t1, 10000); RandomIntArray(t2, 10000);
    // cout<< t1[0] << endl;
    PrintIntArray(t1);
    cout << endl; PrintIntArray(t2);
    if(chooseArrayParts(t1, t2)) cout << "OK" << endl;
    return 0;
}