#include <iostream>

using namespace std;

const int MAX = 4;

bool input (int t[MAX]) {
    for(int i = 0; i < MAX; i++) { 
        cin >> t[i];
        int temp = t[i];
        bool b = false;

        while(temp > 0 and !b) {
            if(temp %2 == 1) b = true;
            temp /= 10;
        }

        if(!b) return false;
    } 
    return true;
}

int main() {
    int t[MAX];
    if(input(t)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}