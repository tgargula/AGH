// Podział liczby na sumy

#include <iostream>

using namespace std;

const int n = 4;
int t[n]; 

int Sums (int ti, int ctr, int maxS) {
    if (ctr == 0 && ti > 1) {
        for(int i = 1; i < ti; i++) cout << t[i] << " + ";
        cout << t[ti] << endl;
    }
    else {
        ti++;
        for(int i = min(ctr,maxS); i > 0; i--) {
            t[ti] = i;
            Sums(ti,ctr-i,i);
        }
    }
}

int main() {
    for(int i = 0; i < n; i++) t[i] = 0;
    Sums(0,n,n);
    return 0;
}