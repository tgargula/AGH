/*
1.Napisać program zamieniający liczbę naturalną z systemu 10 na podstawę 2-16

link do konwertera: https://www.rapidtables.com/convert/number/decimal-to-binary.html?x=120

n - liczba; b - podstawa systemu do którego przeliczamy
niby w treści polecenia jest zalozenie ze ta podstawa nalezy [2,16] ale niema chyba sensu pisac dodatkowego if()
*/

#include<bits/stdc++.h>
using namespace std;

string Converter(int n, int b, string s = "") {
    while(n > 0) {
        s = to_string(n % b) + s;   cout << n % b << endl;
        n = n / b;
    }
    return s;
}

main() {
    int n, b;
    cin >> n >> b;
    cout << Converter(n, b);
    return 0;
}