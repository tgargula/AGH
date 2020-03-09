#include <iostream>

using namespace std;

const int N = 10;

int Nka (int t[N], int n, int suma, int p) {
    if(n == 0) {
        if(suma == 0) return 1;
        else return 0;
    }

    int ile = 0;
    for(int i = p; i < N; i++) {
        ile += Nka (t,n-1,suma-t[i],i+1);
    }

    return ile;
}

int main() {
    int t[N] = {1,2,3,4,5,6,7,8,9,10};
    int n, suma; cin >> n >> suma;
    cout << Nka (t,n,suma, 0) << endl;
    return 0;
}