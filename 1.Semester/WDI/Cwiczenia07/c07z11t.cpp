//Funkcja wypisuje znalezione n-ki (zob. z10)
//Ogólnie działa, ale jeśli t[0] == 1, to nie wypisuje tej jedynki w pierwszym iloczynie
//Jak znajdziecie dlaczego, to poprawcie :)

#include <iostream>

using namespace std;

const int N=10;

int n_ki (int t[N], int n, int m, int p) {   // n_ki (t,2,12,0)
    int sum = 0;
    if(n == 0 and m == 1) {
        cout << endl;
        return 1;
    }
    else if(n == 0 and m != 1) { 
        return 0;
    }
    else {
        for(int i = p; i < N; i++) {
            if(m % t[i] == 0) {
                int temp = n_ki(t,n-1,m/t[i],i+1);
                if (temp >= 1) {
                    cout << t[i] << " ";
                    sum += temp;
                }
            }
        }
    }
    return sum;
}

int main() {
    int t[N] = {2,2,3,4,5,1,7,1,24,10};
    int n, m; cin >> n >> m;
    n_ki(t,n,m,0);
    cout << endl;
    return 0;
}