#include<bits/stdc++.h>

using namespace std;

int a1 = 0, b1 = 1, sum1 = 0, a2 = 1, b2 = 1, sum2 = 1, n;

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
        n += 1; 
        a1 = 0; b1 = 1; sum1 = a1+b1;
        sum2 = a2+b2;
        cout << "n " << n << endl;
        while(n != sum2 - sum1 && flag) {
            if(sum2 - sum1 > n) Sum1(); cout << "sum1 " << sum1 << endl;
            if(sum2 - sum1 < n) Sum2(); cout << "sum2 " << sum2 <<endl;
            if(sum2 < sum1) {
                cout << n; 
                flag = false;
            }
        }
    }
}

main() {
    cin >> n;
    while (sum2 < n) {
        Sum2();
    }
    cout << "summ2 " << sum2 << endl;
    FindNext();
    // while(b1 < n) {
    //     Sum1();
    // }
    return 0;
}