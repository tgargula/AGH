#include <iostream>
#include <cmath>

using namespace std;

int factorial (int n) {
    int out = 1, i = 1;
    while(i<=n) {
        out *=i;
        i++;
    }
    return out;
}

int main() {
    long double x, sum=1;
    long long n=2;
    cin >> x;
    while(n<=24) {
        if(n%4==2) sum -= pow(x,n) / factorial(n);
        else sum += pow(x,n) / factorial(n);
        n+=2;
        cout << sum << " ";
    }

    cout << sum << endl;

    return 0;
}