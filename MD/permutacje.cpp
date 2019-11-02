// Program wypisuje wszystkie permutacje ciągu n-elementowego

#include <iostream>

using namespace std;

const int n = 9;
int t[n];
int j, k, l, i;

int main() {

    for(int i=0; i<n; i++) t[i] = i+1;

    for(int i = 0; i < n; i++) {
        t[i] = i + 1;
    }
    do {
        for(int i = 0; i < n; i++) cout << t[i];
        cout << endl;
        i = n - 2;
        while(i >= 0 && t[i]>t[i+1]) i--;
        if(i >= 0) {
            j = n-1;
            while(t[j] < t[i]) j--;
            swap(t[i], t[j]);
            k = i + 1;
            l = n - 1;
            while(l > k) {
                swap(t[l],t[k]);
                k++;
                l--;
            }
        }
    }   while(i >= 0);


    return 0;
}