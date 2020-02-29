#include <iostream>

using namespace std;

const int MAX = 4;

bool function (int t[MAX][MAX]) {
    bool w[MAX], k[MAX];
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if (t[i][j] == 0) { w[j] = true; k[i] = true; }
            if (t[j][i] == 0) { w[i] = true; k[j] = true; }
        }
    }
    
    for(int i = 0; i < MAX; i++) {
        if(!w[i] or !k[i]) return false;
    }
    return true;
}

int main() {
    int t[MAX][MAX];
    for(int i = 0; i< MAX; i++)
        for(int j = 0; j < MAX; j++) cin >> t[i][j];
    if(function(t)) cout << "YES" << endl; 
    else cout << "NO" << endl;
    return 0;
}