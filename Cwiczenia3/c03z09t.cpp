#include <iostream>

using namespace std;

const int N = 8;

bool arrived (int t[N]) {
    bool c[N];
    c[0] = true;
    for(int i = 1; i < N; i++) c[i] = false;
    for(int i = 0; i < N-1; i++) {
        if(c[i]) {
            int temp = t[i];
            for(int p = 2; p <= N; p++) {
                if(temp % p == 0) {
                    if(i+p < N) c[i + p] = true;
                    if(c[N-1]) return true;
                    while(temp % p == 0) temp /= p;
                }
            }
        }
    }
    return false;
}

int main() {
    int t[N];
    for(int i = 0; i < N; i++) cin >> t[i];
    if(arrived(t)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
