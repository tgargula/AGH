#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>

#ifndef functions_hpp
#define functions_hpp

using namespace std;

const int MAX = 17;
int tab[MAX], tab2[MAX];



/* DECLARATIONS FOR FUNCTIONS */

struct complexNumber {
    double re, im;
};

struct rational {
    int num;    // numerator (licznik)
    int den;    // denominator (mianownik)
};

struct bigInteger {
    string number;
    int numberTab[30000] = {0};
};

void TranslationStringInBigInteger() {

}

struct singleNodePointer {
    int value;
    singleNodePointer *next;
};

struct doubleNodePointer {
    int value;
    doubleNodePointer *prev;
    doubleNodePointer *next;
};

/* MATH */

/* Return factorial from toFactorize number */
string Factorial(int toFactorize) {
    int resultTab[30000]; resultTab[0] = 1; 
    for(int i = 1; i < *(&resultTab + 1) - resultTab; i++) {
        resultTab[i] = 0;
    }
    int tmp;
    for(int i = 2; i <= toFactorize; i++) {
        tmp = 0;
        for(int j = 0; j < *(&resultTab + 1) - resultTab; j++) {
            resultTab[j] *= i; resultTab[j] += tmp;
            tmp = resultTab[j] / 10;
            resultTab[j] %= 10;
        }
    }
    string result = ""; bool ifPrint = false;
    for(int i = *(&resultTab + 1) - resultTab - 1; i >= 0; i--) {
        if(resultTab[i] != 0) ifPrint = true;
        if(ifPrint) result = result + (char)(resultTab[i] + 48);
    }
    return result;
}

/* Matrix determinant (recursive) */ 



/* Great common divisor */
int GreatCommonDivisor(int x, int y) {     // Greatest Common Divisor - NWD; Euclidean algorithm
    x = abs(x);
    if(x < y) swap(x,y);
    int temp;
    while(x%y != 0) {
        temp = x;
        x = y;
        y = temp % y;
    }
    return y;
}

/* Lowest Common Denominator */
int LowestCommonDenominator(int x, int y) {
    return x*y/GreatCommonDivisor(x,y);
}

void CancellingDown (rational &a) {
    if(a.num == 0) a.den = 1;
    else {
        int d = GreatCommonDivisor(a.num, a.den);
        a.num /= d;
        a.den /= d;
    }
}


/* COMPLEX NUMBER */

complexNumber Addition(complexNumber a, complexNumber b) {
    complexNumber c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

complexNumber Substraction(complexNumber a, complexNumber b) {
    complexNumber c;
    c.re = a.re - b.re;
    c.im = a.im - b.im;
    return c;
}

complexNumber Multiplication(complexNumber a, complexNumber b) {
    complexNumber c;
    c.re = a.re*b.re - a.im*b.im;
    c.im = a.re*b.im + a.im*b.re;
    return c;
}

complexNumber Division(complexNumber a, complexNumber b) {
    complexNumber c;
    complexNumber conjugate;
    conjugate.re = b.re;
    conjugate.im = -b.im;

    c = Multiplication(a, conjugate);
    c.re /= Multiplication(b, conjugate).re;
    c.im /= Multiplication(b, conjugate).re;
    return c;
}

complexNumber Exponentation(complexNumber a, int n) {
    complexNumber temp = a;
    for(int i = 1; i < n; i++) a = Multiplication(a,temp);
    return a;
}

void Output(complexNumber z) {
    cout << z.re << " + " << z.im << "i" << endl;
}


/* RATIONALS */

rational Addition (rational a, rational b) {
    rational c;
    c.den = LowestCommonDenominator(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num + b.num;
    CancellingDown(c);
    return c;
}

rational Substraction (rational a, rational b) {
    rational c;
    c.den = LowestCommonDenominator(a.den, b.den);
    a.num *= c.den / a.den;
    b.num *= c.den / b.den;
    c.num = a.num - b.num;
    CancellingDown(c);
    return c;
}

rational Multiplication (rational a, rational b) {
    rational c;
    CancellingDown(a); CancellingDown(b);
    c.num = a.num * b.num;
    c.den = a.den * b.den;
    CancellingDown(c);
    return c;
}

rational Division (rational a, rational b) {
    rational c;
    CancellingDown(a); CancellingDown(b);
    c.num = a.num * b.den;
    c.den = a.den * b.num;
    CancellingDown(c);
    return c;
}

rational Exponentation (rational a, int n) {
    CancellingDown(a);
    int temp1 = a.num;
    int temp2 = a.den;
    for(int i = 1; i < n; i++) {
        a.num *= temp1;
        a.den *= temp2;
    }
    return a;
}


/* BIG NUMBERS */

bigInteger AddBigInt(bigInteger first, bigInteger second) {

}

bigInteger SubstractBigInt(bigInteger first, bigInteger second) {

}

bigInteger MultiplicationBigInt(bigInteger first, bigInteger second) {

}




/* TASKS HELPERS */

int RandomInteger(int min = 0, int max = 100) {
    srand(time(NULL));
    return (rand() % (max - min) + min); 
}

/* Input random integers in default range [0,99] to array */
void RandomIntArray(int Array[], int range = 100) {
    srand(time(NULL)); 
    for(int i = 0; i < *(&Array + 1) - Array; i++) {
        srand(rand());
        Array[i] = rand() % range;
    }
}

/* Print array */
void PrintIntArray(int Array[]) {
    for(int i = 0; i < *(&Array + 1) - Array; i++) {
        cout << Array[i] << " ";
    }
}

/* Print Fibonacci number */
int FindFibonacciNumber(int which, int a = 1, int b = 1) {
    int c, i=1;
    while(i < which) {
        c = a+b;
        a = b;
        b = c;
        i++;
    }
    return a;
}

/* Find next Fibonacci number */
void PrintNextFibonacciNumber(int howMuch = 1, int a = 1, int b = 1) {
    int c, i=1;
    while(i < howMuch) {
        c = a+b;
        a = b;
        b = c;
        cout << a << " ";
        i++;
    }
}

/* TESTS */

/* Tests if number is prime */
bool IsPrime(int n) {
    if(n < 2) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    int i = 5;
    while(i <= sqrt(n)) {
        if(n % i == 0) return false;
        i += 2;
        if(n % i == 0) return false;
        i += 4;
    }
    return true;
}

/* Erastotens Sieve print all prime numbers in range to 1000000 */
void EratostenesSieve(int range = 1000000) {
    bool tab[range]; int i = 2;

    for(int j = 2; j <= range; j++) tab[j] = true;

    for(i = 2; i < sqrt(range); i++) {
        while(!tab[i]) i++;
        for(int k = 2*i; k <= range; k+=i) tab[k] = false;
    }

    for(int j = 2; j <= range; j++) {
        if(tab[j]) cout << j << " ";
    }
}


/* POINTERS */
/*One Direction Lists*/
void insertFirst(singleNodePointer *&first, int val = RandomInteger()) {
    singleNodePointer *newFirst = new singleNodePointer;
    newFirst->value = val;
    newFirst->next = first;
    first = newFirst;
}

void insertLast(singleNodePointer *&first, int val = RandomInteger()) {
    singleNodePointer *newLast = new singleNodePointer;
    singleNodePointer *currentLast = NULL, *nextCurrLast = first;
    newLast->value = val;
    newLast->next = NULL;

    while(nextCurrLast != NULL) {
        currentLast = nextCurrLast;
        nextCurrLast = nextCurrLast->next;
    }
    if(currentLast != NULL) currentLast->next = newLast;
    else first = newLast;
}

void insertByOrder(singleNodePointer *first, int position, int val = RandomInteger()) { /*position=0 - 1st position*/
    if(position <= 0) {insertFirst(first, val); return;}
    int posFinder = 0;
    singleNodePointer *prevNode = NULL; singleNodePointer *nextNode = NULL;
    while(nextNode != NULL and posFinder < position) {

    }
    if(posFinder < position) insertLast(first, val);
}

void deleteFirst(singleNodePointer *&first) {

}

void deleteLast(singleNodePointer *first) {

}

void deleteByValue(singleNodePointer *first, int val) {

}

void deleteByOrder(singleNodePointer *first, int position) {

}

bool belong(singleNodePointer *first, int val) {

}

void listReversion(singleNodePointer *first) {

}

void connectLastElementToFirst(singleNodePointer *first) {

}

bool hasListCycle(singleNodePointer *first) {

}

void printChain(singleNodePointer *first) {

}

void createChain() {

}

/*Two Direction Lists*/



/* SORT METHODS */ 

/* Merge sort - stolen from Wikipedia */ 
void CopyArray(int B[], int A[], int n)
{
    for(int i = 0; i < n; i++)
        A[i] = B[i];
}

void BottomUpMerge(int A[], int iLeft, int iRight, int iEnd, int B[])
{
    int i = iLeft, j = iRight;
    for (int k = iLeft; k < iEnd; k++) {
        if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    } 
}

void BottomUpMergeSort(int A[], int B[MAX], int n)
{
    for (int width = 1; width < n; width = 2 * width)
    {
        for (int i = 0; i < n; i = i + 2 * width)
        {
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        CopyArray(B, A, n);

    }
}


#endif