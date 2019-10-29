// Program wczytuje dwie liczby. Tworzy z nich liczby, takie że wszystkie cyfry podanych liczb znajdują się w niej.
// Ponadto, kolejność cyfr wejściowych jest zachowana.
// Program wylicza, ile istnieje tak złożonych liczb pierwszych
// 
// Prawdopodobnie istnieje lepszy algorytm
// Ten działa dobrze do n = 9; ogólnie słaba złożoność czasowa
// Byłbym wdzięczny, gdyby ktoś to poprawił :)

#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 10; // int ma zakres do 2^31 - 1, czyli liczba 10-cyfrowa
int n;
bool t[MAX];
int a, b, size_a, size_b, ta[10], tb[10];
long long number;
int i, j, k, l, temp, p, q, c;
bool num[2000000000]; // szaleństwo, cała taka tablica zajmowałaby prawie 2GB, gdyby nie było zrzutów pamięci; ogólnie risky 

bool prime(long long n) {
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


int main() {
    cin >> a >> b;
    size_a = size_b = 0;
    temp = a;
    while(temp > 0) {
        ta[size_a] = temp % 10;
        temp /= 10;
        size_a++;
    }

    temp = b;
    while(temp > 0) {
        tb[size_b] = temp % 10;
        temp /= 10;
        size_b++;
    }

    n = size_a + size_b;

    for(int i = 0; i < size_a; i++) t[i] = false;
    for(int i = size_a; i < n; i++) t[i] = true;        // tworzymy tablicę bool: false oznacza, że trzeba wziąć cyfrę z pierwszej liczby; true - z drugiej

    do {
        number = 0; p = size_a - 1; q = size_b - 1;
        for(int i = 0; i < n; i++) {
            number *= 10;
            if(!t[i]) {
                number += ta[p];
                p--;
            }
            else {
                number += tb[q];
                q--;
            }
        }       // tworzymy kolejną liczbę
        num[number] = true; // aby nie liczyć wielokrotnie pierwszych, które się powtarzają, zaznaczamy, że dana liczba wystąpiła
        // cout << number << endl;
        i = n - 2;
        while(i >= 0 && t[i]>=t[i+1]) i--;
        if(i >= 0) {
            j = n-1;
            while(t[j] <= t[i]) j--;
            swap(t[i], t[j]);
            k = i + 1;
            l = n - 1;
            while(l > k) {
                swap(t[l],t[k]);
                k++;
                l--;
            }
        }
    }   while(i >= 0);  // algorytm tworzący kolejne permutacje multizbioru dwuwyrazowego (tablica bool)

    c = 0;
    for(int i = pow(10,n-1); i < pow(10,n); i++) if(num[i] && prime(i)) c++;

    cout << c << endl;

    return 0;
}