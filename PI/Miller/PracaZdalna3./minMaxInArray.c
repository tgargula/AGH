#include <stdio.h>
#include <limits.h>

int minimum(int a, int b) {return a < b ? a : b;}
int maximum(int a, int b) {return a > b ? a : b;}

void findMinAndMaxInArray(int array[], int arraySize, int *mini, int *maxi) {           // computational complexity 3/2n + 1
    // arraySize = sizeof(array) / sizeof(array[0]);
    if((arraySize) % 2 == 0) {
        for(int i = 0; i < arraySize; i += 2) {
            if(array[i] < array[i+1]) {
                *mini = minimum(*mini, array[i]);
                *maxi = maximum(*maxi, array[i+1]);
            } else {
                *mini = minimum(*mini, array[i+1]);
                *maxi = maximum(*maxi, array[i]);
            }
        }
    } else {
        for(int i = 0; i < arraySize - 1; i += 2) {
            if(array[i] < array[i+1]) {
                *mini = minimum(*mini, array[i]);
                *maxi = maximum(*maxi, array[i+1]);
            } else {
                *mini = minimum(*mini, array[i+1]);
                *maxi = maximum(*maxi, array[i]);
            }
        }
        *mini = minimum(*mini, array[arraySize - 1]);
        *maxi = maximum(*maxi, array[arraySize - 1]);
    }
}

int main() {
    int array[] = {1};
    int a = INT_MAX, b = INT_MIN, *mini = &a, *maxi = &b, arraySize = *(&array + 1) - array;
    findMinAndMaxInArray(array, arraySize, mini, maxi);
    printf("min = %d, max = %d\n", *mini, *maxi);
    return 0;
}