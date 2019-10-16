// Program wypisuje ostatnią niezerową cyfrę n!

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int x2, x3, x5, x7, i, t, last =1; 
    x2 = x3 = x5 = x7 = 0;
    
    i=2;
    while(i<=n) {
        t = i;
        while(t%2==0) {     // Pętla sprawdza potęgi 2 w n!
            x2++;
            t/=2;
        }
        while(t%5==0) {     // Pętla sprawdza potęgi 5 w n!
            x5++;
            t/=5;
        }
        t %= 10;
        last *= t;
        last %= 10;
        i++;
    }   

    x2 -= x5;

    for(int i=1;i<=x2;i++) {
        last *= 2;
        last %= 10;
    }

    cout << last << endl;

    return 0;
}