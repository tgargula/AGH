/*
Autor: 
2. Znaleźć wyrazy początkowe zamiast 1,1 o najmniejszej sumie, aby w ciągu analogicznym do ciągu Fibonacciego wystąpił wyraz równy numerowi bieżącego roku.
*/

#include <iostream>

using namespace std;

const int y=2019;

bool fib(int a, int b) {
    int c;
    while(a<y) { 
        c = a+b;
        a = b;
        b = c;
    }
    if(a==y) return true;
    return false;
}   

int main() {
    int a=1,b=1,n=2;
    for(;n<2019;n++,a=1,b=n-1) {
        for(;b>0;a++,b--) {
            if(fib(a,b)) {
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }
}