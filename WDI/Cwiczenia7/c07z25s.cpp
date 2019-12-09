#include <iostream>
#include <math.h>

using namespace std;

const int N = 7;
int t[N];

void RandomArray() {
    srand(time(NULL)); 
    for(int i = 0; i < N; i++) {
        srand(rand());
        t[i] = rand() % 100;
        cout << t[i] << '\t';
    }
    cout << '\n';
}

bool Pierwsza(int i) {
    if(i == 2) return true;
    if(i == 3) return true;
    if(i % 2 == 0) return false;
    if(i % 3 == 0) return false;
    for(int j = 5; j < sqrt(i); ) {
        if(i % j == 0) return false;
        j += 2;
        if(i % j == 0) return false;
        j += 4;
    }
    return true;
}

int Droga(int t[N], int pozycja, int kroki, bool &dotarl) {
    // int kroki = 0;
    cout << "pozycja " << pozycja << endl;
    if (pozycja == N-1) {
        dotarl = true;
        return kroki;
    }
    for(int i = 2; i <= sqrt(t[pozycja]); i++) {
        // if(Pierwsza(i)) cout << "pierwsza " << i << endl;
        if(Pierwsza(i) and t[pozycja] % i == 0 and pozycja + i < N) {
            cout << "kroki " << kroki << " i " << i << endl;
            Droga(t, pozycja + i, kroki, dotarl);
            kroki++; 
        }
    }
    if(dotarl == false) { 
        kroki = -1;
    }
    return kroki; 
}

int main () {
    RandomArray(); int kroki = 0; bool dotarl = false;
    cout << Droga(t, 0, kroki, dotarl) << endl;
    return 0;
}