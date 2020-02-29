// Program odpowiada na pytanie, czy liczba n jest wielokrotnością dowolnego wyrazu ciągu A(n):
// A(n) = 3 * A(n-1) + 1

#include <iostream>

using namespace std;

const int MAX = 20; // MAX = 20, żeby wyrazy ciągu nie wychodziły poza zakres int
int n, A[MAX], i;
bool b = false;

int main() {
    cin >> n;
    A[0] = 2;

    for(i = 1; i < MAX && A[i-1] <= n; i++) {
        if(n % A[i-1] == 0) {
            b = true;
            break;
        }
        A[i] = 3 * A[i-1] + 1;
    }

    if(b) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
