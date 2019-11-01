/*
2. Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
czy liczba ta jest wielokrotnością dowolnego wyrazu ciągu danego wzorem
A(n)=n*n+n+1.
*/

#include <iostream>

using namespace std;

int main() {
    int n,s=1,i=0;
    cin >> n;

    while(s<n) {
        s = i*i + i + 1;
        i++;
    }

    if(s == n) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}