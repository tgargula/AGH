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

bool marchOfKing (int t[N][N], int w, int k, int last, int corner) { //marchOfKing(t,w,k,10,1)
    int wmove = 1, kmove = 1, wend = N-1, kend = N-1;
    if(corner == 2 or corner == 3) { wmove *= -1; wend = 0; } 
    if(corner == 3 or corner == 4) { kmove *= -1; kend = 0; }

    if (k == N or w == N or k < 0 or w < 0) return false;
    int temp = t[w][k]; while(temp >= 10) temp /= 10;  
    if (temp >= last) return false;
    if (w == wend and k == kend) return true;
    
    return marchOfKing(t, w+wmove, k      , t[w][k]%10, corner) or
           marchOfKing(t, w+wmove, k+kmove, t[w][k]%10, corner) or
           marchOfKing(t, w      , k+kmove, t[w][k]%10, corner);
}

bool directions (int t[N][N], int w, int k) {
    return marchOfKing(t,w,k,10,1) or   // 1 - punkt (N-1, N-1)
           marchOfKing(t,w,k,10,2) or   // 2 - punkt ( 0 , N-1)
           marchOfKing(t,w,k,10,3) or   // 3 - punkt ( 0 ,  0 )
           marchOfKing(t,w,k,10,4);     // 4 - punkt (N-1,  0 )
}

int main() {
    int t[N][N];
    randomArray(t);
    output(t);

    int w, k; cin >> w >> k;
    if(directions(t,w,k)) cout << "YES" << endl;
    return 0;
}