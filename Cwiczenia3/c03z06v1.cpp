// Program wypisuje 10 największą liczbę z ciągu liczb zakończonym zerem

#include <iostream>

using namespace std;

const int MAX = 1000;
int tab[MAX];
int i,m;

int main() {
    i = 0;
    do {
        cin >> tab[i];
        i++;
    } while(tab[i-1] != 0);
    for(int k = 0; k<10-1; k++) {
        m = 0;
        for(int j = 0; j < i-1; j++) if(tab[j] > m) m = tab[j];
        for(int j = 0; j < i-1; j++) if(m == tab[j]) {
            tab[j] = -1;
        }
    }
    
    m = 0;
    for(int j = 0; j < i-1; j++)
        if(m < tab[j]) m = tab[j];

    cout << m << endl;

    return 0;
}