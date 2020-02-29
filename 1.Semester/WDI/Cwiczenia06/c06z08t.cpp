#include <iostream>

using namespace std;

const int N = 8;

bool GreedyKing (int t[N][N], int w, int k, int cash) {
    if(k < 0 or k >= N) return false;
    if(w == N-1) return true;
    return (t[w+1][k-1] > cash)
    // return GreedyKing (t, w+1, k-1, t[w][k]) or
    //        GreedyKing (t, w+1, k, t[w][k]) or
    //        GreedyKing (t, w+1, k+1, t[w][k]);

}

void RandomArray(int tab[N][N]) {
    // srand(time(NULL));                  //aby otrzymać takie same wartości w tablicy za każdym razem wystarczy zakomentować linijkę srand(time(NULL)); 
    for(int i = 0; i < N; i++) {      //lub zmienić początkowy seed na inny niż NULL
        for(int j = 0; j < N; j++) { 
            srand(rand());
            tab[i][j] = rand() % 100;
            cout << tab[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t[N][N];
    RandomArray(t);
    if(GreedyKing(t,0,4,t[0][4])) cout << "YES";
    return 0;
}