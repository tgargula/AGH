// Program przyjmuje dwie liczby i oblicza ich stosunek zaznaczając przy tym okres

#include <iostream>

using namespace std;

int max25 (int b) {     // Będzie tyle miejsc po przecinku nie w okresie, ile wynosi największa potęga 2 lub 5
    int i2, i5, t;
    i2 = i5 = 0;
    
    t = b;
    while(t % 2 == 0) {
        i2++;
        t /= 2;
    }

    t = b;
    while(t % 5 == 0) {
        i5++;
        t /= 5;
    }

    return max(i2, i5);
}

int main() {
    int a, b, t, r, m;
    cin >> a >> b;

    cout << a/b;
    m = max25(b);
    t = a % b;

    if(a % b != 0) {
        cout << ".";
        for(int i = 0; i < m; i++) {
            t %= b;
            t *= 10;
            cout << t/b;
        }
        if(t % b != 0) {
            r = t%b;
            cout << "(";
            do {
                t %= b;
                t *= 10;
                cout << t/b;
            }   while(r != t%b);
            cout << ")";
        }
    }
    cout << endl;

    return 0;
}