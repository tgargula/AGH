/*
19.Napisać program wyznaczający wartość liczby e korzystając z zależności: e = 1/0! + 1/1! + 1/2! + 1/3! + ... 
*/

#include<bits/stdc++.h>
using namespace std;

const long long accuracy = 31;

long long result[accuracy];

void Division(/*long long result[],*/long long divisor) {
    long long temp = 1;
    for(long long i = 0; i < accuracy; i++) {
        result[i] = result[i] + temp / divisor;
        if(result[i] > 9) {
            result[i-1] = result[i-1] + result[i] / 10;
            result[i] = result[i] % 10;
        }
        temp = (temp % divisor) * 10;
    }
}

void Printer(long long result[]) {
    cout << 2 << ",";
    for(long long i = 1; i < accuracy; i++) cout << result[i];
    cout << endl;
}

int main() {
    //long long result[accuracy]; 
    long long divisor = 1;
    for(long long i = 0; i < accuracy; i++) {result[i] = 0;}
    for(long long i = 2; i < 21; i ++) {
        divisor = divisor * i;
        cout << divisor << endl;
        Division(divisor);
    }

    //Division(17);
    Printer(result);
    return 0;
}

// long long main() {
//     double result = 1, help = 1;
//     for(double i = 1; i < 1000; i++) {
//         help = help / i;
//         result = result + help; 
//     }
//     cout << setprecision(30) << result; return 0;
// }