

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int MAX = 31;
double tab[MAX][MAX];

int main(){
    int t=MAX/2;
    int k=MAX/2;
    tab[k][t]=1;
    int temp=1;
    int ks, ts;

        for(int i=1;temp<=(MAX)*(MAX);i++){
            ks=i;
            ts=i;
            do{
            if(temp==MAX*MAX) goto koniec;
            temp++;
            ts--;
            t=t+pow(-1,i);
            tab[k][t]=temp;
            }
            while(ts>0);

            do{
            if(temp==MAX*MAX) goto koniec;
            temp++;
            ks--;
            k=k+pow(-1,i);
            tab[k][t]=temp;}
            while(ks>0);
        }

    koniec:
        for(int i=0;i<=MAX-1;i++){
        for(int j=0;j<=MAX-1;j++){
        cout<<tab[j][i]<< "\t";}
        cout<<endl;
        }
}