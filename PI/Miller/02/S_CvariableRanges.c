#include <stdio.h>
#include <limits.h>

int intRange(int i) {
    printf("%s", "start");
    while(i >= 0) {
        i+=1;
    }
    printf("%s\n", "i");
    i-=1;
    return i;
}

double doubleRange(double i) {
    printf("%s", "start");
    while(i >= 0) {
        i+=1.0;
    }
    printf("%s", "d");
    return i;
}

float floatRange(float i) {
    while(i >= 0) {
        i+=1.0;
    }
    printf("%s", "f");
    return i;
}

long long int lliRange(long long int i) {       // to optimize
    while(i >= 0) {
        printf("%lld\n", i);
        i+=1000;
    }
    printf("%s\n", "l");
    i -= 1;
    return i;
}

int main(){
    int d = 0;
    double lf = 1.0;
    float f = 0.0;
    long long int lld = 0;

    printf("%s\n", "lele");

    // d = intRange(d);
    // printf("%d\n", d);
    // lf = doubleRange(lf);
    // printf("%lf", lf);

    // lld = lliRange(lld);
    printf("%lld\n", (__LONG_LONG_MAX__)+1);

    // printf("%d", intRange(d)-1);
    // printf("%lf", doubleRange(lf)-1);
    // printf("%f", floatRange(f)-1);
    // printf("%lld", lliRange(lld)-1);

    return 0;
}