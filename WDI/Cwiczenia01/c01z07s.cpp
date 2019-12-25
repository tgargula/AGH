/*
7. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie, 
czy liczba ta jest iloczynem dowolnych dwóch kolejnych wyrazów ciągu Fibonacciego.
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 1, b = 1, help; cin >> n;

    while(a * b <= n) {
        if(a * b == n) {
            cout << "JEST"; return 0;
        }
        help = b; b = a + b; a = help;
    }
    cout << "NIE JEST"; return 0;
}