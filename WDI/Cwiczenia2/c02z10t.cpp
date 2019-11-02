/*
10. Napisać program, który oblicza pole figury pod wykresem funkcji y=1/x w przedziale
od 1 do k, metodą prostokątów.
*/

// y = 1/x , k>1, zliczanie pola pod wykresem w przedziale <1,k>
//całkowanie numeryczne - metoda prostokątów
// s_i = step*y

#include <iostream>

using namespace std;

const double step = 1e-6;

int main() {
    double k,x=1,s=0;
    cin >> k;

    while(x<k) {
        s+=step/x;
        x+=step;
    }

    cout << s << endl;

    return 0;

}