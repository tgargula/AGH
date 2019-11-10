/*
6. Napisać program rozwiązujący równanie x^x=2019 metodą bisekcji.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double y = 2019;
const double eps = 1e-3;

int main() {
    double a=1,b=5, c;
    while(eps<abs(pow(a,a)-pow(b,b))) {
        c = (a+b)/2;
        if(pow((a+b)/2,(a+b)/2)>y) b=(a+b)/2;
        else a=(a+b)/2;
    }
    cout << (a+b)/2 << endl;
    return 0;
}