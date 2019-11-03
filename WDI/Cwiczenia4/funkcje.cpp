#include <bits/stdc++.h>

using namespace std;

//Liczby pierwsze
bool IfPrime(int n) {
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

//Ciąg Fibonacciego - wypisywanie
int Fib(int n) {
    int a=1,b=1,c,i=1;
    while(i<n) {
        c = a+b;
        a = b;
        b = c;
        i++;
    }
    return a;
}

//Ciąg Fibonacciego - znajdowanie następnych wyrazów
void Fib2(int a, int b, int help = 0) {     //a większa; b mniejsza
    help = a;
    a = a + b;
    b = help;
}


int main() {

}