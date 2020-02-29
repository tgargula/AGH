#include <iostream>

using namespace std;

const int N = 8;

void RandomArray(int t[N][N]) {
    //srand(time(NULL));                  //aby otrzymać takie same wartości w tablicy za każdym razem wystarczy zakomentować linijkę srand(time(NULL)); 
    for(int i = 0; i < N; i++) {      //lub zmienić początkowy seed na inny niż NULL
        srand(rand());
        for(int j = 0; j < N; j++)
            t[i][j] = rand() % 10 +1;
    }
}

void Output(int t[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cout << t[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

bool Possible (int t[N][N], int i, int c, int &nc) {
    nc = c + i;
    return nc >= 0 and nc < N;
}

int min (int a, int b) {

}

int GreedyKing(int t[N][N], int r, int c, int sum, int &mini) {
    int nc;
    if(r == N - 1) return t[r][c];
    else {
        if(r == 0) return min(GreedyKing (t,r+1, c-1, ));
        else if(r == N-1) return min(t[r+1][c], t[r+1][c-1]);
        else return min(t[r+1][c-1], min(t[r+1][c],t[r+1][c+1]));
    }
}

int main() {
    static int t[N][N];
    int mini = INT32_MAX;
    int c; cin >> c;
    RandomArray(t);
    Output(t);
    GreedyKing(t,0,c,t[0][c],mini);

    return 0;
}