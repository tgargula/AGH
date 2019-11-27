// Program zlicza n-ki o podanym iloczynie

#include <iostream>

using namespace std;

const int N = 10;


int ctr = 0;
void enki (int t[N], int n, int s, int p) {
    if(n == 1) { for(int i = p; i < N; i++) if(t[i] == 0) ctr++; cout << "a";}
    else { for(int i = p; i < N-n+1; i++) if(s%t[i] == 0) enki(t,n-1,s/t[i],i+1); }
}

int main() {
    int t[N] = {2,2,2,2,2,2,2,2,2,2};
    enki(t,3,4,0);
    cout << ctr << endl;
    return 0;
}