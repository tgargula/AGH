// Funkcja sprawdza, czy istnieje taki wiersz tablicy t[MAX][MAX], że każda liczba w nim zawarta zawiera co najmniej jedną cyfrę nieparzystą

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX = 10;

bool function (int t[MAX][MAX]) {   // Funtion checks if such a row exists that every number includes at least one odd digit #sorry for my English xDD
    for(int j = 0; j < MAX; j++) {
        int i = 0;
        bool b = true;
        while(i < MAX && b) {
            b = false;
            int temp = t[i][j];
            // cout << temp << "\t";    // Test - prints current row
            while(temp > 0) {
                if(temp % 2 == 1) { b = true; break; }
                temp /= 10;
            }
            i++;
        }
        // cout << endl;
        if(i == MAX && b) return true;
    }
    return false;
}

int main() {
    int t[MAX][MAX];
    srand(time(NULL));
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            t[j][i] = rand() % 100;
    
    // for(int i = 0; i < MAX; i++) {       // Test - prints t[MAX][MAX]
    //     for(int j = 0; j < MAX; j++)
    //         cout << t[j][i] << "\t";
    //     cout << endl;
    // }
    // cout << endl;

    if(function(t)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
