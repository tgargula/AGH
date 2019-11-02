/*
19.Napisać program wyznaczający wartość liczby e korzystając z zależności: e = 1/0! + 1/1! + 1/2! + 1/3! + ... 
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    double result = 1, help = 1;
    for(double i = 1; i < 1000; i++) {
        help = help / i;
        result = result + help; 
    }
    cout << setprecision(30) << result; return 0;
}