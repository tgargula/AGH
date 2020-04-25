// Program wypisuje liczbę, gdy jest ona średnią arytmetyczną 4 najbliższych sąsiadów w ciągu zakończonym zerem, stanowiącym wyłącznie znacznik końca danych

#include <iostream>

using namespace std;

const int MAX = 1000;
int tab[MAX];
int i, j, t;

int main() {
    i = -1;
    do {
        i++;
        cin >> tab[i];
    }   while(tab[i] != 0);

    for(j = 2; j + 2 <= i; j++) {
        t = tab[j-2] + tab[j-1] + tab[j+1] + tab[j+2];
        if(t % 4 == 0 && tab[j] == t/4) cout << tab[j] << " ";
    }
    cout << endl;

    return 0;
}