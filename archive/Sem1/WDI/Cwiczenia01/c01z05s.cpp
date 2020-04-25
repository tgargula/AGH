/*
5. Napisać program wyznaczający pierwiastek kwadratowy ze wzoru Newtona.
*/
#include<bits/stdc++.h>     //jedna biblioteka zastępuje wiele bibliotek (przynajmniej w teorii)

using namespace std;

const double eps = 1e-3;

int main() {
    double s, a, b=1;
    cin >> s;
    while(abs(b-a)>eps) {
        a = b;
        b = (s/a + a)/2;
    }

    cout << b << endl;

    return 0;
}