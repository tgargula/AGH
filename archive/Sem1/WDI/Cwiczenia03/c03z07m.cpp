/*
7.Napisać program wypełniający tablicę int t[MAX] liczbami naturalnymi 1-1000 i sprawdzającyczy każdy element tablicy zawiera co najmniej jedną cyfrę nieparzystą
*/

#include <iostream>

using namespace std;

const int n = 4;

int main() {  
    bool val=true;
    int tab[n];
    for(int i=0;i<n;i++) cin>>tab[i];

    for(int i=0;i<n;i++) {
        int temp=tab[i];
        while(temp%2==0 && temp!=0) temp/=10;
            if(temp==0) {
                val=false;
                goto koniec;
            }
    }
    
koniec:
    if(val) cout<<"YES";
    else cout<<"NO";
    return 0;
}
