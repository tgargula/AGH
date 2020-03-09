//Funkcja zlicza, ile istnieje n-ek o podanym iloczynie

#include <iostream>

using namespace std;

const int N=10;

int n_ki (int t[N], int n, int m, int p) {   // n_ki (t,2,12,0)
    int sum = 0;
    if(n == 0 and m == 1) {
        return 1;
    }
    else if(n == 0 and m != 1) { 
        return 0;
    }
    else {
        for(int i = p; i < N; i++) {
            if(m % t[i] == 0) {
                sum += n_ki(t,n-1,m/t[i],i+1);
            }
        }
    }
    return sum;
}

int main() {
    int t[N] = {1,2,3,4,5,6,7,8,24,10};
    int n, m; cin >> n >> m;
    cout << n_ki(t,n,m,0) << endl;
    return 0;
}