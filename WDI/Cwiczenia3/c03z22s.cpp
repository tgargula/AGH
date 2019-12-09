#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

void RandomArray(int t[]) {
    // srand(time(NULL));                  //aby otrzymać takie same wartości w tablicy za każdym razem wystarczy zakomentować linijkę srand(time(NULL)); 
    for(int i = 0; i < N; i++) {      //lub zmienić początkowy seed na inny niż NULL
        srand(rand());
        t[i] = rand() % 100;
        cout << t[i] << '\t';
    }
    cout << '\n' ;
}

int Najdluzszy(int t[]) {
    int najdluzszy = 0, czyNajdluzszy = 1, sumaInd = 0, sumaPodc = t[0];
    for(int i = 1; i < N; i++) {
        sumaPodc = t[i-1]; sumaInd = i-1;
        while(t[i-1] < t[i] && i < N) {
            czyNajdluzszy++; cout << "czyNajdluzszy " << czyNajdluzszy << endl;
            sumaInd += i; cout << "sumaInd " << sumaInd << endl;
            sumaPodc += t[i]; cout << "sumaPodc " << sumaPodc << endl;
            if(sumaPodc == sumaInd) {
                najdluzszy = max(najdluzszy, czyNajdluzszy);
                cout << "OK" << endl;
            }
            i++;
        }
        
        cout << "najdluzszy " << najdluzszy << endl;
        czyNajdluzszy = 1;
    }
    return najdluzszy;
}

int main() {
    int t[N];
    // RandomArray(t);
    for(int i = 0; i < N; i++)  {
        t[i] = i;
        cout << i << '\t';
    }
    cout << '\n';
    t[5] = 1344;
    cout<< Najdluzszy(t) << endl;

    return 0;
}