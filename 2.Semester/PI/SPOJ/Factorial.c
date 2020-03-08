// https://www.spoj.com/problems/FCTRL/

#include<stdio.h>

int Z(int num) {
    int result = 0;
    for(int i = 5; num / i >= 1; i *= 5) {
        result += num / i;
    }
    return result;
}

int main() {
    int n, temp;
    scanf("%d", &n);
    while(n > 0) {
        scanf("%d", &temp);
        printf("%d\n", Z(temp));
        n-=1;
    }
}
