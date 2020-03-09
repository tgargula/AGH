#include <iostream>

using namespace std;

const int N = 5;

void Output(int t[N][N]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) cout << t[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool Possible(int t[N][N], int i, int r, int c, int &nr, int &nc) {
    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {-2,-1,1,2,2,1,-1,-2};
    nc = c + dx[i];
    nr = r + dy[i];
    return nc >= 0 and nc < N and nr >= 0 and nr < N and t[nr][nc] == 0;
}

// void Knight_Jump (int t[N][N], int r, int c, int n) {
//     t[r][c] = n;
//     if(n == N*N) Output(t);
//     else {
//         for(int i = 0; i < 8; i++) {
//             int nr, nc;
//             if(Possible(t,i,r,c,nr,nc)) Knight_Jump(t,nr,nc,n+1);
//         }
//     }
//     t[r][c] = 0;
// }

// void Knight_Jump (int t[N][N], int r, int c, int n) {
//     t[r][c] = n;
//     if(n == N*N) Output(t);
//     else {
//         for(int i = 0; i < 8; i++) {
//             int nr, nc;
//             if(Possible(t,i,r,c,nr,nc)) Knight_Jump(t,nr,nc,n+1);
//         }
//     }
//     t[r][c] = 0;
// }

void Knight_Jump (int t[N][N], int r, int c, int n, bool b) { //Knight_Jump(t,0,0,0,false)
    if(b) return;
    t[r][c] = n;
    if(n == N*N) { Output(t); b = true; return; }
    else {
        for(int i = 0; i < 8; i++) {
            int nr, nc;
            if(Possible(t,i,r,c,nr,nc)) Knight_Jump(t,nr,nc,n+1,b);
        }
    }
    t[r][c] = 0;
}

int main() {
    static int t[N][N];
    Knight_Jump(t,0,0,1,false);
    return 0;
}