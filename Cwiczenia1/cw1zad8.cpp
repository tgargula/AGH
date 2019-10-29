/*
8.Napisać program sprawdzający czy zadana liczba jest pierwsza.

*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; //int sqr = static_cast<int> (sqrt(n)); - to jest taka zamiana float -> int ale nie wiem czy dozwolone
    for(int i = 2; i <= (sqrt(n)) + 1; i++) {
        if(n % i == 0) {
            cout << "FUCK OFF! - czyli nie jest"; return 0;
        }
    }
    cout << "OK - czyli jest pierwsza"; return 0;
}