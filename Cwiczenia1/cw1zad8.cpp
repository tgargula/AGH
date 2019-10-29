/*
8.Napisać program sprawdzający czy zadana liczba jest pierwsza.

*/

#include<bits/stdc++.h>
using namespace std;

bool prime(int n) {
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    int i = 5;
    while(i <= sqrt(n)) {
        if(n % i == 0) return false;
        i += 2;
        if(n % i == 0) return false;
        i += 4;
    }
    return true;
}

int main() {
    int n; cin >> n; //int sqr = static_cast<int> (sqrt(n)); - to jest taka zamiana float -> int ale nie wiem czy dozwolone
    // for(int i = 2; i <= (sqrt(n)) + 1; i++) {
        // if(n % i == 0) {
            // cout << "FUCK OFF! - czyli nie jest"; return 0;
        // }
    // }
    // cout << "OK - czyli jest pierwsza"; return 0;
    if(prime) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
