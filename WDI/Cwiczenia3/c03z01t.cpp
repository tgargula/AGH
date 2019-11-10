#include <iostream>

using namespace std;

int main() {
    int n;
    int tab[32];
    int i;
    cin >> n;
    
    for(int p = 2; p <= 16; p++) {
        int temp = n;
        for(i = 0; temp > 0; i++) {
            tab[i] = temp%p;
            temp /= p;
        }
        for(int k = i-1; k >= 0; k--) {
            if(tab[k] < 10) cout << tab[k];
            else {
                if(tab[k] == 10) cout << "A";
                else if(tab[k] == 11) cout << "B";
                else if(tab[k] == 12) cout << "C";
                else if(tab[k] == 13) cout << "D";
                else if(tab[k] == 14) cout << "E";
                else cout << "F";
            }
        }
        cout << endl;
    }

    return 0;
}
