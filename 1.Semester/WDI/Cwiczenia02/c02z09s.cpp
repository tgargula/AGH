/*
9. Pewnych liczb nie można przedstawić jako sumy elementów spójnych fragmentów ciągu
Fibonacciego, np. 9,14,15,17,22. Proszę napisać program, który wczytuje liczbę
naturalną n, wylicza i wypisuje następną taką liczbę większą od n. Można założyć,
że 0<n<1000.
*/

#include<bits/stdc++.h>

using namespace std;

int a1, b1, sum1, a2 = 1, b2 = 1, sum2 = 1, n;

void Sum1() {
    int h = b1;
    b1 = b1 + a1;
    a1 = h;
    sum1 = sum1 + a1;
}

void Sum2() {
    int h = b2;
    b2 = b2 + a2;
    a2 = h;
    sum2 = sum2 + a2;
}

void FindNext() {
    bool flag = true;
    while(flag) {
        if (sum2 < n) Sum2();
        n += 1; 
        a1 = 1; b1 = 1; sum1 = 1;
        // cout << "n " << n << endl;
        // cout << "sum2 " << sum2 <<endl;
        while(n != sum2 - sum1 && flag && sum2 > n) {
            // cout << "sum1 " << sum1 << endl;
            if(sum2 - sum1 > n) Sum1(); 
            if(sum2 - sum1 < n) flag = false; 
        }
            // cout << "sum1 " << sum1 << endl;        
    }
}

main() {
    cin >> n;
    while (sum2 < n) Sum2();
    // cout << "summ2 " << sum2 << endl;
    FindNext();
    cout << n << endl;
    // while(b1 < n) {
    //     Sum1();
    // }
    return 0;
}
