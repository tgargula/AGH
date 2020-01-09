//Program zlicza, ile liczb dwu-trzy-piątkowych znajduje się w przedziale 1 do N włącznie
//Liczby dwu-trzy-piątkowe to takie, które można przedstawić w postaci: x = 2^a * 3^b * 5^c
//gdzie a,b,c należą do całkowitych nieujemnych

#include <iostream>

using namespace std;

int main() {
    int N, x=0;
    cin >> N;

    for ( int i2 = 1 ; i2 <=N ; i2 *= 2 )                   //liczbę domnażamy przez 2, potem przez 3, potem przez 5
        for ( int i3 = i2 ; i3 <=N ; i3 *= 3 )              //liczbę domnażamy przez 3, potem przez 5
            for ( int i5 = i3 ; i5 <=N ; i5 *= 5 ) x++;     //liczbę domnażamy przez 5

    cout << x << endl;

    return 0;
}

//Przykład: N = 20
//  i2  i3  i5 - liczby 2-3-5-kowe
//  1   1   1
//  1   1   5
//  1   3   3
//  1   3   15
//  1   9   9
//  2   2   2
//  2   2   10
//  2   6   6
//  2   18  18
//  4   4   4
//  4   4   20
//  4   12  12
//  8   8   8
//  16  16  16
//  RAZEM:  14 liczb
//złożoność <= N