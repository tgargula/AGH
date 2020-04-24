#include <stdio.h>

int main() {
    int x;
    for(x = 0; x < 10; x++) {
        if(x%2 == 0)continue;
        printf("%d ", x);
    }
    x = 0; printf("llslsls\n");
    while(x < 10) {
        if(x%2 ==0) {
            continue;
        }
        printf("%d ", x);
        x++;
    }

}