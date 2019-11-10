/*
3.Napisać program generujący i wypisujący liczby pierwsze mniejsze od N metodą Sita Eratostenesa
*/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 2000000000;
int n, i;
bool tab[MAX];

int main() {
    cin >> n;

    for(int j = 2; j <=n; j++) tab[j] = true;

    for(i = 2; i < sqrt(n); i++) {
        while(!tab[i]) i++;
        for(int k = 2*i; k <= n; k+=i) tab[k] = false;
    }

    for(int j = 2; j <= n; j++) {
        if(tab[j]) cout << j << " ";
    }

    return 0;
}
