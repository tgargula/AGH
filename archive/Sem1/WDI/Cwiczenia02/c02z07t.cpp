/*
7. Napisać program wczytujący liczbę naturalną z klawiatury i rozkładający ją na
iloczyn 2 liczb o najmniejszej różnicy. Np. 30=5*6, 120=10*12.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int a=sqrt(n); a>=1; a--)
        if(n%a == 0) {
            cout << n << "=" << a << "*" << n/a << endl;
            return 0;
        }

    // cout << n << "=" << 1 << "*" << n << endl;

    return 0;
}