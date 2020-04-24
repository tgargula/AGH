#include <stdio.h>

// Some assumptions:
// xs -start of range; xc - center point of range; xe - finish of range

long double f(long double x) {
    // if(x == 0.5) return 0;
    // return 1/((x-0.5)*(x-0.5))+0.01;        
    // return x;
    // return x*x*x + 2*x*x - 18*x + 23;
    return 5/((x-0.3)*(x-0.3)*(x-0.3)) + 3*x*x - 100*x*x*x*x*x + 123*x; 
}

long double absoluteDouble(long double x) {
    if(x < 0.0) return x * (-1.0);
    return x;
}

long double surface(long double xs, long double xe, long double xc) {
    // printf("f(xs) = %Le, f(xc) = %Le, f(xe) = %Le\n", f(xs), f(xc), f(xe));
    return absoluteDouble((xe - xs) * (f(xs) + 4 * f(xc) + f(xe)) / 6);     // surface is always positive
}

long double simpsonIntegral(long double xs, long double xe, long double delta, long double surf, int recursionLevel, int *stopRecursion) {
    if(*stopRecursion == 1) return 0.0;
    if(recursionLevel == 0) {
        *stopRecursion = 1; return 0.0;
    }
    long double xc = (xe - xs) / 2 + xs, surfLeft = surface(xs, xc, (xc - xs) / 2 + xs), surfRight = surface(xc, xe, (xe - xc) / 2 + xc);
    // printf("xs = %Le, xc = %Le, xe = %Le, delta = %Le, h = %Le\nsurfL = %Le, surfR = %Le, surf = %Le, abs = %Le\n", xs, xc, xe, delta, (xe-xs), surfLeft, surfRight, surf, absoluteDouble((surfLeft + surfRight) - surf));
    if(absoluteDouble((surfLeft + surfRight) - surf) <= delta) {/*printf("end recursion branch\n")*/; return surf;}
    else return simpsonIntegral(xs, xc, delta/2, surfLeft, recursionLevel - 1, stopRecursion) + simpsonIntegral(xc, xe, delta/2, surfRight, recursionLevel - 1, stopRecursion);
}

int main() {
    long double xs, xe, delta, result;
    int stopRecursion = 0, *stopRec = &stopRecursion;
    scanf("%Le %Le %Le", &xs, &xe, &delta);
    long double xc = (xe - xs) / 2 + xs;
    result = simpsonIntegral(xs, xe, delta, surface(xs, xe, xc), 64, stopRec);
    if(stopRecursion == 1) printf("NaN\n");
    else printf("%Le\n", result);

    return 0;
}