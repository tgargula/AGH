#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int n = 4;
int main() {
bool val=true;
int tab[n];
for(int i=0;i<n;i++)
    cin>>tab[i];

    for(int i=0;i<n;i++){
        int temp=tab[i];
         while(temp%2==0 && temp!=0) temp/=10;
            if(temp==0){
                val=false;
                goto koniec;
            }

    }
    koniec:
    if(val) cout<<"YES";
    else cout<<"NO";

}
