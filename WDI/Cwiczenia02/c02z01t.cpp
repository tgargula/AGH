/*
1. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, czy liczba ta jest iloczynem dowolnych dwóch wyrazów ciągu Fibonacciego.
*/

#include <iostream>
#include <cmath>

using namespace std;

int fib(int i) {                // Wyznaczenie i-tego wyrazu ciągu Fib
    int a = 1, b = 1, c, k=1;
    while(k < i) {
        c = a + b;
        a = b;
        b = c;
        k++;
    }
    return a;
}

bool mult = false;

int main() {
    int n;
    int m=1;
    cin >> n;

    for(int i=2; fib(i) <= n; i++) {                // Sprawdzamy od 2, bo 1 i 2 wyraz ciągu Fib to 1
        for(int j=i; m <= n; j++) {     // j = i, żeby nie powtarzać
            m = fib(i)*fib(j);      
            // cout << fib(i) << " " << fib(j) << " ";      TESTY
            // cout << fib(i)*fib(j) << endl;               TESTY
        
            if(m == n) mult = true;
            if(mult) break;

        }
        if(mult) break;
    }

    if(mult) cout << "YES" << endl;
    else cout << "NOPE" << endl;

    return 0;
}
