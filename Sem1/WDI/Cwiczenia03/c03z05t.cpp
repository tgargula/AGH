// Program wyznacza liczbę e, korzystając ze wzoru:
// e = 1/0! + 1/1! + 1/2! + 1/3! + ...

#include <iostream>

using namespace std;

const int PREC = 2050;

int main() {
    int tab[PREC], e[PREC];
    int p;

    tab[0] = 1; e[0] = 1;
    for(int i = 1; i < PREC; i++) {
        tab[i] = 0;
        e[i] = 0;
    }

    for(int i = 1; i < PREC; i++) {
        p = 0;
        for(int j = 0; j < PREC; j++) {
            tab[j] += p;
            p = tab[j]%i * 10;
            tab[j] /= i;
        }   // dzielenie poprzedniego składnika przez kolejną liczbę i
        p = 0;
        for(int j = PREC-1; j >= 0; j--) {
            e[j] += tab[j]%10 + p;
            p = e[j]/10;
            e[j] %= 10;
        }   // dodawanie nowego składnika do wyniku
    }

    cout << e[0] << ".";
    for(int i = 1; i < 2001; i++) cout << e[i];

    return 0;
}
