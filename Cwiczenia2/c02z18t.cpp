// Program wyznacza trójki Pitagorejskie

#include <iostream>

using namespace std;

int a,b,c;
const int m = 1000;

int main() {
    for(a = 1; a < m; a++) {
        for(b = a; b < m; b++) {
            c = a;
            while(c*c < a*a + b*b) c++; 
            if(c*c == a*a + b*b) cout << a << " " << b << " " << c << endl;
        } 
    }

    return 0;
}
