// Program wyznacza liczbę a/b z dokładnością do n miejsc po przecinku
// Algorytm dzielenia pisemnego

#include <iostream>

using namespace std;

int main() {
    int a,b,n;
    cin >> a >> b >> n;

    cout << a/b << ".";

    for(int i=0;i<n;i++) {
        a %= b;
        a *=10;
        cout << a/b;
    }

    cout << endl;

    return 0;
}