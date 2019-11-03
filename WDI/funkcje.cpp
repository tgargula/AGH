#include <bits/stdc++.h>

using namespace std;

const int MAX = 17000;

//Czy liczba jest pierwsza
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

//Silnia sporych liczb
string Factorial(int n, string result = "") {
    bool b = false;
    int p;
    int tab[MAX];

    for(int i = 1; i < MAX; i++) tab[i] = 0;
    tab[0] = 1;

    for(int i = 2; i <= n; i++) {
        p = 0;
        for(int j = 0; j < MAX; j++) {
            tab[j] *= i; tab[j] += p;
            p = tab[j]/10;
            tab[j] %= 10;
        }
    }

    for(int k = MAX-1; k>=0; k--) {
        if(tab[k] != 0) b = true;
        if(b) result = result + char(tab[k] + 48);
    }

    return result;
}

//Dodawanie liczb zmiennoprzecinkowych z dużą dokładnścią
//...

//Sito Eratostenesa
void EratostenesSieve() {
    bool tab[MAX]; int i = 2;

    for(int j = 2; j <= MAX; j++) tab[j] = true;

    for(i = 2; i < sqrt(MAX); i++) {
        while(!tab[i]) i++;
        for(int k = 2*i; k <= MAX; k+=i) tab[k] = false;
    }

    for(int j = 2; j <= MAX; j++) {
        if(tab[j]) cout << j << " ";
    }
}


int main() {
    // int n; cin >> n;
    // cout << Factorial(n);
    
    
    return 0;
}