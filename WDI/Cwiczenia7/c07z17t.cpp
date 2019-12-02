#include <iostream>

using namespace std;

const int N = 8;

void randomArray(int t[N][N]) {
    srand(time(NULL));                  //aby otrzymać takie same wartości w tablicy za każdym razem wystarczy zakomentować linijkę srand(time(NULL)); 
    for(int i = 0; i < N; i++) {      //lub zmienić początkowy seed na inny niż NULL
        //srand(rand());
        for(int j = 0; j < N; j++)
            t[i][j] = rand() % 10 +1;
    }
}

void output(int t[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cout << t[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

bool marchOfKing (int t[N][N], int w, int k, int last) { //marchOfKing(t,w,k,INT32_MAX)
    if (k == N or w == N) return false;
    int temp = t[w][k]; while(temp >= 10) temp /= 10;  
    if (temp >= last) return false;
    if (w == N-1 and k == N-1) return true;
    return marchOfKing(t, w+1, k, t[w][k]%10) or
           marchOfKing(t, w+1, k+1, t[w][k]%10) or
           marchOfKing(t, w, k+1, t[w][k]%10);
}

int main() {
    int t[N][N];
    randomArray(t);
    output(t);

    int w, k; cin >> w >> k;
    if(marchOfKing(t,w,k,INT32_MAX)) cout << "YES" << endl;
    return 0;
}
