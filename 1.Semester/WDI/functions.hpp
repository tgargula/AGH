#include <iostream>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

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

struct node {
    int value;
    node *next;
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
void RandomIntArray(int Array[], int arraySize, int range = 100) {
    srand(time(NULL));
    for(int i = 0; i < arraySize; i++) {
        srand(rand()); 
        Array[i] = rand() % range;
    }
}
/*experimental*/
void RandomIntArrayExperimental(int Array[], int range = 100) {
    srand(time(NULL)); cout << *(&Array + 1) - Array <<endl;
    for(int i = 0; i < *(&Array + 1) - Array; i++) {
        srand(rand()); 
        Array[i] = rand() % range;
        cout << i << " ";
    }
    cout << endl;
}

/* Print array */
void PrintIntArray(int Array[], int arraySize) {
    for(int i = 0; i < arraySize; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}
/*experimental*/
void PrintIntArrayExperimental(int Array[]) {
    for(int i = 0; i < *(&Array + 1) - Array; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
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

int FindFibonacciNuberRecursive(int which) {
    if(which == 1) return 1;
    if(which == 2) return 1;
    return FindFibonacciNuberRecursive(which - 1) + FindFibonacciNuberRecursive(which - 2);
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

/*One Direction Lists - no sentinel*/

void insertFirst(node *&first, int val) {
    node *newFirst = new node;
    newFirst->value = val;
    if(first == NULL) newFirst = first;
    else {
        newFirst->next = first;
        first = newFirst;
    }
}

void insertLast(node *&first, int val = RandomInteger()) {
    node *newLast = new node;
    node *currentLast = NULL, *nextCurrLast = first;
    newLast->value = val;
    newLast->next = NULL;

    while(nextCurrLast != NULL) {
        currentLast = nextCurrLast;
        nextCurrLast = nextCurrLast->next;
    }
    if(currentLast != NULL) currentLast->next = newLast;
    else first = newLast;
}

void testInsertLast(node *&first, int val = RandomInteger()) {
    node *newLast = new node;
    node *currentLast = first;
    newLast->value = val;
    newLast->next = NULL;

    if(currentLast == NULL) {currentLast->next = newLast; return;}
    while(currentLast->next != NULL) {
        currentLast = currentLast->next;
    }
    currentLast->next = newLast;
}

void insertByOrder(node *first, int position, int val = RandomInteger()) { /*position=0 - 1st position*/
    if(position <= 0) {insertFirst(first, val); return;}
    int posFinder = 1;
    if(first->next == NULL and position == 1) {
        insertLast(first, val);
    } else {
        node *prevElem = first, *nextElem = first->next;
        while(nextElem != NULL and posFinder < position) {
            prevElem = nextElem;
            nextElem = nextElem->next;
            posFinder++;
        }
        if(posFinder < position) {insertLast(first, val); return;}
        if(posFinder == position) {
            node *newElem = new node;
            newElem->value = val;
            newElem->next = prevElem->next;
            prevElem->next = newElem;
        }
    }
}

void deleteFirst(node *&first) {
    if(first == NULL) return;
    if(first->next == NULL) {
        delete first;
        first = NULL;
        return;
    } else {
        node *temp = first;
        first = first->next;
        delete temp;
    }
}

void deleteLast(node *first) {
    if(first == NULL) return;
    if(first->next == NULL) {
        delete first;
        first = NULL;
        return;
    } else {
        node *currentLast = first, *newLast = NULL;
        while(currentLast->next != NULL) {
            newLast = currentLast;
            currentLast = currentLast->next;
        }
        delete currentLast;
        newLast->next = NULL;
    }
}

void deleteByValue(node *first, int val) {
    if(first == NULL) return;
    if(first->next == NULL) {
        if(first->value == val) delete first;
    } else {
        node *prevElem = first, *nextElem = first->next;
        while(nextElem->next != NULL and nextElem->value != val) {
            prevElem = nextElem;
            nextElem = nextElem->next;
        }
        if(nextElem->value == val) {
            node *tmp = nextElem;
            nextElem = nextElem->next;
            prevElem->next = nextElem;
            delete tmp;
        }
    }
}

void deleteByOrder(node *first, int position) {
    if(position <= 0) {deleteFirst(first); return;}
    int posFinder = 1;
    if(first->next == NULL and position == 1) {
        deleteLast(first);
    } else {
        node *prevElem = first, *nextElem = first->next;
        while(nextElem != NULL and posFinder < position) {
            prevElem = nextElem;
            nextElem = nextElem->next;
            posFinder++;
        }
        if(posFinder < position) {deleteLast(first); return;}
        if(posFinder == position) {
            node *tmp = nextElem;
            nextElem = nextElem->next;
            delete tmp;
            prevElem->next = nextElem;
        }
    }
}

bool belong(node *first, int val) {
    if(first == NULL) return false;
    if(first->next == NULL) if(first->value == val) return true;
    while(first->next != NULL) {
        if(first->value == val) return true;
        first = first->next;
    }
    return false;
}

node * listReverse(node *first) {
    if(first == NULL or first->next == NULL) return first;

    node *prevElem = first, *currElem = first->next, *nextElem = first->next;
    prevElem->next = NULL;

    while(currElem != NULL) {
        nextElem = nextElem->next;
        currElem->next = prevElem;
        prevElem = currElem;
        currElem = nextElem;
    }

    return prevElem;
}

bool hasListCycle(node *first) {
    if(first == NULL) return false;
    if(first->next == first) return true;
    node *fasterFirst = first;
    while(first->next != NULL and fasterFirst->next != NULL) {
        first = first->next; fasterFirst = fasterFirst->next;
        if(fasterFirst->next == NULL) return false;
        else fasterFirst = fasterFirst->next;
        if(first == fasterFirst) return true;
    }
    return false;
}

// bool isListCycle(node *first) {
//     node *findLast = first;
//     while(findLast->next != NULL) {
//         if(findLast->next == first) return true;
//         findLast = findLast->next;
//     }
//     return false;
// }

int listLength(node *first) {
    if(hasListCycle(first)) {
        cout << "cycle list" << endl; return 1234567;
    }
    if(first == NULL) return 0;
    if(first->next == NULL) return 1;
    int length = 1;
    while(first->next != NULL) {
        first = first->next;
        length++;
    }
    return length;
}

void createRandomCycle(node *first, int startCycleElem) {
    // if(listLength(first) < 2) return;
    // cout << "start make cycle" << endl;
    // usleep(1000000);
    if(hasListCycle(first)){ return;}
    node *lastElem = first, *startCycle = first;
    while(startCycleElem > 0 and lastElem->next != NULL) {
        // cout << lastElem->next << " last" << endl;
        lastElem = lastElem->next; startCycle = startCycle->next; startCycleElem--;
    }
    while(lastElem->next != NULL) {
        // cout << lastElem->next << " last" << endl;
        lastElem = lastElem->next;
    }
    lastElem->next = startCycle; 
    return;
}

void connectLastElementToFirst(node *first) {
    node *findLast = NULL, *help = first;
    while(help != NULL) {
        findLast = help;
        help = help->next;
    }
    if(findLast != NULL) findLast->next = first;
}

node * createList(int numberOfElements = 10, bool regular = true, int range = 10000) {
    node *first = new node;
    if(regular) {
        first->value = numberOfElements;
        for(int i = 1; i < numberOfElements; i++) {
            insertFirst(first, numberOfElements-i);
        }
    } else {
        srand(time(NULL));
        first->value = rand() % range;
        for(int i = 1; i < numberOfElements; i++) {
            srand(rand());
            insertFirst(first, rand() % range);
        }
    }
    return first;
}

node * createCycleList(int numberOfElements = 10) {
    node *first = new node;
    first->value = numberOfElements;
    for(int i = 1; i < numberOfElements; i++) {
        insertFirst(first, numberOfElements-i);
    }
    connectLastElementToFirst(first);
    return first;
}

node * createListWithCycle(int numberOfElements = 10, int startCycleElem = 0) {
    node *first = new node;
    first->value = numberOfElements;
    for(int i = 1; i < numberOfElements; i++) {
        insertFirst(first, numberOfElements-i);
    }
    cout << "OK 1" << endl;
    if(startCycleElem == 0) startCycleElem = RandomInteger(0, listLength(first));
    cout << startCycleElem << " " << "OK2 " << endl;
    createRandomCycle(first, startCycleElem); cout << "OK3" << endl;
    return first;
}

int countElemsInCycle(node *first) {
    if(first == NULL) return 0;
    if(first == first->next) return 1;
    node *fasterFirst = first->next;
    while(fasterFirst != NULL and fasterFirst != first) {
        first = first->next; fasterFirst = fasterFirst->next;
        if(fasterFirst != NULL) fasterFirst = fasterFirst->next;
    }
    if(fasterFirst == NULL) {
        cout << "no cycle" << endl; return 0;
    }

    int length = 1; fasterFirst = first->next;
    while(fasterFirst != first) {
        fasterFirst = fasterFirst->next; length++;
    }
    return length; cout << length << " 2" << endl;

    // else {
    //     node *counter = first->next; int length = 1;
    //     while(counter != first) {
    //         counter = counter->next; cout << counter->value << " " << counter->next << endl;
    //         usleep(2000000);
    //         length++; cout << length << " " << endl;
    //     } 
    //     return length;
    // }
}

int cycleListReverseWithCount(node *first) {
    if(first == NULL or first->next == first) return 0;

    node *prevElem = first, *currElem = first->next;
    if(currElem->next == first) return 0;
    if(currElem->next == currElem) return 1;

    node *nextElem = first->next;
    prevElem->next = NULL;

    int result = 0;
    while(currElem != NULL) {
        nextElem = nextElem->next;
        currElem->next = prevElem;
        prevElem = currElem;
        currElem = nextElem;
        result++; // cout << result << endl;
    }
    
    // while(nextElem != NULL) {
    //     currElem->next == first;
    //     first = currElem;
    //     currElem = nextNode;
    //     nextNode = nextNode->next;
        
    //     cout << "reversion" << endl;
    // }
    // currentNode->next = first;
    return result; cout << result << "1 " << endl;
}

int countElemsBeforeCycle(node *first) {
    int result = (0 - countElemsBeforeCycle(first) + cycleListReverseWithCount(first))/2;
    cout << result << endl;
    return result;
}

void printListElements(node *first, bool addresses = false) {       /*No cycle lists*/
    if(first == NULL) return;
    if(addresses) cout << &first << "->";
    while(first != NULL) {
        cout << first->value << " ";
        if(addresses and first->next != NULL) cout << first->next << "->";
        first = first->next;
    }
    cout << endl;
    // node *goAlongList = first; 
    // if(addresses) cout << &first << "->";
    // cout << goAlongList->value << " ";
    // goAlongList = goAlongList->next;
    // if(addresses) cout << &first << "->";
    // while(goAlongList != first) {
    //     cout << goAlongList->value << " ";
    //     if(addresses and goAlongList->next != first) cout << goAlongList->next << "->";
    //     goAlongList = goAlongList->next;
    // }
    // cout << endl;
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