/*
10.Napisać program wyszukujący liczby doskonałe mniejsze od miliona.

Liczba doskonała - suma jej podzielników mniejszych od niej samej jest jej równa

*/

#include<bits/stdc++.h>
using namespace std;

bool IsPrime(int summ){
    for(int i = 2; i <= (sqrt(summ)) + 1; i++) {
        if(summ % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int sum = 0, last = 1;
    while(sum * last < 1000000) {
        sum = sum + last;
        //cout << " sum " << sum <<endl;
        if(IsPrime(sum)) cout << sum * last << endl;
        last = last * 2;
    }
}