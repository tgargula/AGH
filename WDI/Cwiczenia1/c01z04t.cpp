/*
4. Napisać program obliczający pierwiastek całkowitoliczbowy z liczby naturalnej korzystając z zależności 1+3+5+... = n^2.
*/

#include <iostream>

using namespace std;

int main() {
    int x, sum=0, i=0, n=1;
    cin >> x;

    while(sum<=x) {
        sum += n;
        i++;
        n += 2;
    }

    cout << i-1 << endl;

    return 0;
}