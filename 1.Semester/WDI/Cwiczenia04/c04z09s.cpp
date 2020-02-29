#include <bits/stdc++.h>

using namespace std;

struct info {
    bool czyIstnieje;
    int srodekX;
    int srodekY;
};

const int MAX = 10;
int Tab[MAX][MAX];

void ZapchajSie() {
    srand(time(NULL)); 
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            srand(rand());
            Tab[i][j] = rand() % 100;
            cout << Tab[i][j] << '\t';
        }
        cout << '\n';
    }
}

bool Iloczyn(int k, int rogX, int rogY, int dlugoscBoku){
    int result = Tab[rogX][rogY]*Tab[rogX + dlugoscBoku][rogY]*Tab[rogX][rogY + dlugoscBoku]*Tab[rogX + dlugoscBoku][rogY + dlugoscBoku];
    if(result == k) return true;
    return false;
}

info Szukaj(int Tab[MAX][MAX], int k) {
    info OK; OK.czyIstnieje = false;
    for(int dlugoscBoku = 2; dlugoscBoku < MAX-1; dlugoscBoku += 2) {
        for(int x = 0; x < MAX-dlugoscBoku; x++) {
            for(int y = 0; y < MAX-dlugoscBoku; y++) {
                if(Iloczyn(k, x, y, dlugoscBoku)){
                    OK.czyIstnieje = true;
                    OK.srodekX = x + dlugoscBoku/2;
                    OK.srodekY = y + dlugoscBoku/2;
                    return OK;
                }
                if(Iloczyn(k, y, x, dlugoscBoku)){
                    OK.czyIstnieje = true;
                    OK.srodekY = x + dlugoscBoku/2;
                    OK.srodekX = y + dlugoscBoku/2;
                    return OK;
                }
            }
        }
    }
    return OK;
}

int main() {
    ZapchajSie();
    int k; cin >> k;
    info OK;
    OK = Szukaj(Tab, k);
    if(OK.czyIstnieje) {
        cout << "x " << OK.srodekX << '\n';
        cout << "y " << OK.srodekY << '\n';
    } else {
        cout << "Nie istnieje" << endl;
    }
    return 0;
}