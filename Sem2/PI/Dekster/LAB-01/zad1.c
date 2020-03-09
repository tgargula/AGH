#include <stdio.h>

int main(void) {
    double a;
    int x, p;
    printf("Input a unit price: ");
    scanf("%lf", &a);
    printf("Input a number of units: ");
    scanf("%d", &x);
    printf("Input a tax value: ");
    scanf("%d", &p);

    double netto = a * x;
    double inTotal = netto + netto*p/100;

    printf("Netto price:\t%.2lf\n", netto);
    printf("In total:\t%.2lf\n", inTotal);

    return 0;
}