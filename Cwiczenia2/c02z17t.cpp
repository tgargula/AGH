// Program wyznacza wszystkie N-cyfrowe liczby, takie że suma cyfr tej liczby podniesiona do N-tej potęgi jest równa tej liczbie

#include <iostream>
#include <cmath>

using namespace std;

int N, x1, x2, p, SUM;

int main() {
    cin >> N;
    x1 = 1;
    for(int i = 1; i < N; i++) x1*=10;
    x2 = x1 * 10;

    SUM = 0;
    while(x1 < x2) {
        p = x1;
        while(p > 0) {
            SUM += pow(p%10,N);
            p /= 10;
        }
        if(SUM == x1) cout << x1 << " ";
        x1++;
        SUM = 0;
    }


    cout << endl;
    return 0;
}
