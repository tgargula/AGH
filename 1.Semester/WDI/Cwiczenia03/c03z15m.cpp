/*
15.Napisać program wyznaczający na drodze eksperymentu prawdopodobieństwo tego, 
że w grupie N przypadkowo spotkanych osób, co najmniej dwie urodziły się tego samego dnia roku. 
Wyznaczyć wartości prawdopodobieństwa dla N z zakresu 20-40.
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

//n to liczba dni w roku
//k to liczba osób

const int N = 365;

using namespace std;

double Prob (double k) {
    double ilo = 1;
    for(double i = 0; i < k; i++) {
        ilo *= (1 - i / N);
    }
    return 1 - ilo;
}

void ProperRange() {
    double k = 20;
    while( k < 41 ) {
        cout << Prob(k) << endl;
        k ++ ;
    }
}

int main(){
    ProperRange();
    return 0;
}