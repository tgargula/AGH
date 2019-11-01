/*
10.Napisać program wyszukujący liczby doskonałe mniejsze od miliona.

Liczba doskonała - suma jej podzielników mniejszych od niej samej jest jej równa

*/

#include<bits/stdc++.h>
using namespace std;

bool IsPrime(int summ){
    if(summ < 2) return false;
    if(summ == 2 || summ == 3) return true;
    if(summ % 2 == 0 || summ % 3 == 0) return false;
    int i = 5;
    while(i <= sqrt(summ)) {
        if(summ % i == 0) return false;
        i += 2;
        if(summ % i == 0) return false;
        i += 4;
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