/*
14. Napisać program obliczający wartości cos(x) z rozwinięcia w szereg Maclaurina.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.141592653;

long long factorial (long long n) {
    long long out = 1, i = 1;
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
    while(x < -pi) x += 2*pi;
    while(x > pi) x-= 2*pi; 
    while(n<=20) {
        if(n%4==2) sum -= pow(x,n) / factorial(n);
        else sum += pow(x,n) / factorial(n);
        n+=2;
    }

    cout << sum << endl;

    return 0;
}