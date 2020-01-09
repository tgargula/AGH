/*
3. Napisać program sprawdzający czy istnieje spójny podciąg ciągu Fibonacciego o zadanej sumie.
*/

#include <iostream>

using namespace std;

int fib (int n) {
    int a=1,b=1,c,i=1;
    while(i<n) {
        c = a+b;
        a = b;
        b = c;
        i++;
    }
    return a;
}

int main () {
    int a=1,b=2,s;
    int sum = 2;
    cin >> s;

    if(s==1) { cout << "YES" << endl; return 0; }
    while(a<b) {
        if(sum==s) {
            cout << "YES" << endl;
            return 0;
        }
        else if(sum<s) {
            b++;
            sum+=fib(b);
        }
        else {
            sum-=fib(a);
            a++;
        }
    }
    cout << "NO" << endl;
    return 0;
}
