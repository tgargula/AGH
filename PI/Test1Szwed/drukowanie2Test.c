#include <stdio.h>

int main() {
    int x=1, y=2;
    if(x&&y) {
        printf("1");
    }
    if(x&y) {
        printf("2");
    }
    if(x&&y&&x) {
        printf("3");
    }
    if(x&&y&&x&y) {
        printf("4");
    }
}