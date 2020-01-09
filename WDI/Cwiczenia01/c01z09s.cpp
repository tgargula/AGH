/*
9. Napisać program wypisujący podzielniki liczby.

Zakładam, że 1 jest podzielnikiem każdej liczby dlatego sprawdzam od 2
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            cout << i << endl;
            cout << n / i << endl;
        }
    }
    cout << n << endl;
    return 0;
}