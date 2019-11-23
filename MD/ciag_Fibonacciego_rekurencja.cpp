#include<bits/stdc++.h>
using namespace std;

long long maxi = 0;

long long Fibonacci(long long n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (Fibonacci(n - 1) + Fibonacci(n - 2) > maxi) {
        cout << Fibonacci(n - 1) + Fibonacci(n - 2) << endl;
        maxi = Fibonacci(n - 1) + Fibonacci(n - 2);
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    long long n; cin >> n;
    Fibonacci(n);
    return 0;
}