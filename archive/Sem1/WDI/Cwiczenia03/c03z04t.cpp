// Program liczy silnię z dużych liczb (do 1000!)

#include <iostream>

using namespace std;

const int MAX = 2568; //1000! ma 2568 cyfr; dla większych silni trzeba zwiększyć odpowiednio MAX

int main() {
    int n, p;
    int tab[MAX];
    bool b = false;
    cin >> n;

    for(int i = 1; i < MAX; i++) tab[i] = 0;
    tab[0] = 1;

    for(int i = 2; i <= n; i++) {       //tworzy tablicę wyniku silni od tyłu
        p = 0;
        for(int j = 0; j < MAX; j++) {
            tab[j] *= i; tab[j] += p;
            p = tab[j]/10;
            tab[j] %= 10;
        }
    }

    for(int k = MAX-1; k>=0; k--) {
        if(tab[k] != 0) b = true;
        if(b) cout << tab[k];
    }

    return 0;
}
