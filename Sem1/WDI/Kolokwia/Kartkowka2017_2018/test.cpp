#include <iostream>

using namespace std;

int main(){
    bool tab[16] = {false};
    for (int i = 0; i < 16; i++){
        if (tab[i]) {cout << "True";}
        else {cout << "False";}
    }
}