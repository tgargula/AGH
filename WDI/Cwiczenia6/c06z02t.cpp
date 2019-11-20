#include <iostream>

using namespace std;

const int N = 15;

bool Istnienia (int t[N], int p, int sum) {
    if (sum == 0) return true;
    if (p == N) return false;
    return (Istnienia(t,p+1,sum-t[p]) or Istnienia(t,p+1,sum)) or Istnienia(t,p+1,sum+t[p]);  
}

void RandomArray(int tab[N]) {
    //srand(time(NULL));                  //aby otrzymać takie same wartości w tablicy za każdym razem wystarczy zakomentować linijkę srand(time(NULL)); 
    for(int i = 0; i < N; i++) {      //lub zmienić początkowy seed na inny niż NULL
        srand(rand());
        tab[i] = rand() % 10 + 1;
        cout << tab[i] << "\t";
    }
}

int main() {
    int t[N];
    RandomArray(t);
    int sum;
    cin >> sum;
    if(Istnienia(t,0,sum)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}