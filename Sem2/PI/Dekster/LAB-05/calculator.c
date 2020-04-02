#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

inline void setNumberOfOperandsAndLengthOfEveryNumber (int *n, short *k) { scanf("%d%hd", n, k); }
inline void printResult (int res) { printf("%d\n", res); }

inline bool isNumber (char *string) { return string[0] >= '0' && string[0] <= '9'; } // Supposing the string is correctly built

inline void add (int *stack, int sizeOfStack) { stack[sizeOfStack-2] += stack[sizeOfStack-1]; }
inline void substract (int *stack, int sizeOfStack) { stack[sizeOfStack-2] -= stack[sizeOfStack-1]; }
inline void multiply (int *stack, int sizeOfStack) { stack[sizeOfStack-2] *= stack[sizeOfStack-1]; }
inline void divide (int *stack, int sizeOfStack) { stack[sizeOfStack-2] /= stack[sizeOfStack-1]; }

int makeNumberOutOf (char *string) {

    int res = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        res *= 10;
        res += (int)(string[i] - '0');
    }

    return res;

}

int scanCharactersAndCalculateResult (int n, int k) {
    
    int numberOfCharacters = 2 * n - 1; // n operands and n-1 operators
    
    int *stack = malloc (n * sizeof(int));
    int sizeOfStack = 0;

    for (int i = 0; i < numberOfCharacters; i++) {
        char *string = malloc ((k+1) * sizeof(char));
        scanf("%s", string);

        if (isNumber(string)) { stack[sizeOfStack] = makeNumberOutOf(string); sizeOfStack++; }
        else {
            if (string[0] == '+') add(stack, sizeOfStack);
            else if (string[0] == '-') substract(stack, sizeOfStack);
            else if (string[0] == '*') multiply(stack, sizeOfStack);
            else if (string[0] == '/') divide(stack, sizeOfStack);
            sizeOfStack--;
        }

        free(string);
    }

    int result = stack[0];
    free(stack);

    return result;

}


int main() {

    int n; short k;
    setNumberOfOperandsAndLengthOfEveryNumber(&n, &k);
    printResult(scanCharactersAndCalculateResult(n, k));

    return 0;

}