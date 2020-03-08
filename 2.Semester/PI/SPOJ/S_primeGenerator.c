// Wypisuje wszystkie liczby pierwsze z zadanego zakresu.

#include <stdio.h>
#include <math.h>

int isPrime(int number) {
    if(number < 2) return 0;
    if(number == 2) return 2;
    if(number == 3) return 3;
    if(number%2 == 0 || number%3 == 0) return 0;
    int i = 5;
    while(i <= sqrt((double) number)) {
        if(number % i == 0) return 0;
        i += 2;
        if(number % i == 0) return 0;
        i += 4;
    }
}

int findFirstPrime(int minRange, int maxRange) {
    while(minRange <= maxRange) {
        // printf("%c\n", 'p');
        if(isPrime(minRange) != 0) break;
        minRange+=1;
    }
    return minRange;
}

void findPrimesInRange(int minRange, int maxRange) {
    // if(minRange < 2 && maxRange >= 2) printf("%d\n", 2);
    minRange = findFirstPrime(minRange, maxRange);
    if(minRange == 2) {
        printf("%d\n", minRange);
        minRange +=1;
    }
    for(int i = minRange+2; minRange <= maxRange; minRange+=2) {
        if(isPrime(minRange) != 0) printf("%d\n", minRange);
    }
    printf("%c", '\n');
}

int main() {
    int howMuch, minRange, maxRange;
    scanf("%d", &howMuch);
    for(int i = 0; i < howMuch; i+=1) {
        scanf("%d %d", &minRange, &maxRange);
        findPrimesInRange(minRange, maxRange);
    }
    return 0;
}