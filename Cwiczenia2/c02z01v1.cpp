/*
Autor:
1. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta jest iloczynem dowolnych dwóch wyrazów ciągu Fibonacciego.
*/

//Do poprawy
// wywalić dodatkowe cout i testy w komentarzach

#include<bits/stdc++.h>

using namespace std;

int n, low1 = 1, low2 = 1, high1 = 1, high2 = 1;

void Fibonacci(int a, int b, bool x = true, int help = 0) {
    help = b;
    b = a + b;
    a = help;
    if(x) {
        high1 = a; high2 = b;
    } else {
        low1 = a; low2 = b;
    }
}

main() {
    cin >> n;

    while(low2 <= n) {
        high1 = low1; high2 = low2;
        while(low2 * high2 <= n) {
            if(low2 * high2 == n) {
                cout << "YES"; return 0;
            }
            Fibonacci(high1, high2, true);
            cout << high1 << " " << high2 <<endl;
            cout << low1 << " " << low2 << endl;
        }
        Fibonacci(low1, low2, false);
    }
    cout << "NO"; return 0;

    // int i = 0;
    // while(i < 10) {
    //     Fibonacci(low1, low2, false);
    //     cout << low2 << endl;
    //     i++;
    // }
}