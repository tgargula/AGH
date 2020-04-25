// Program wyznacza liczby Smitha

#include <iostream>
#include <cmath>

using namespace std;

int n, sum1, sum2, t;

int main() {
    cout << "hey";
    cin >> n;
    cout << "HeY'";
    sum1 = sum2 = 0;
    t = n;
    while(t > 0) {
        sum1 += t % 10;
        t /= 10;
    }

    for(int i = 0; i <= sqrt(n); i++) {
        if(n % i == 0) {
            t = i;
            while(t > 0) {
                sum2 += t % 10;
                t /= 10;
            }
            t = n / i;
            while(t > 0) {
                sum2 += t % 10;
                t /= 10;
            }
        }
    }

    if(sum1 == sum2) cout << "YES";
    return 0;
}
