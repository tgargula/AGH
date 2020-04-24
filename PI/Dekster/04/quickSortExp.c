#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME "results.csv"

char *quickSortTypeDescription[5] = {
    "Classic quick sort",
    "Quick sort with randomization", 
    "Median of three quick sort",
    "Median of three quick sort with insertion sort",
    "Built-in qsort"
};

char *generateMethodDescription[8] = {
    "Random (max = n/10)",
    "Random (max = n*10)",
    "Sorted",
    "Almost sorted (distValue = .025)",
    "Almost sorted (distValue = .25)",
    "Almost sorted reversed (distValue = .25)",
    "Almost sorted reversed (distValue = .025)",
    "Sorted reversed"
};

inline void swap (int *a, int *b) {
    
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

int qsortCompare (const void *a, const void *b) {   // inner function of qsort

    int _a = *(int*) a;
    int _b = *(int*) b;
    return _a == _b ? 0 : _a < _b ? 1 : -1;

}


/* Array generators */

void generateRandom (int *tab, size_t n, int maxValue) {

    for (int i = 0; i < n; i++) tab[i] = lrand48() % maxValue;

}

void generateSorted (int *tab, size_t n) {

    for (int i = 0; i < n; i++) tab[i] = n;

}

void generateSortedReverse (int *tab, size_t n) {

    for (int i = 0; i < n; i++) tab[i] = n - i;

}

void makeDistortions (int *tab, size_t n, double distValue) {

    int M = (int) (n * distValue);
    for (int i = 0; i < M; i++) {
        int a = lrand48() % n;
        int b;
        do { b = lrand48() % n; } while (a == b);
        swap (&tab[a], &tab[b]);
    }

}

void generateAlmostSorted (int *tab, size_t n, double distValue) {

    generateSorted(tab, n);
    makeDistortions(tab, n, distValue);

}

void generateAlmostSortedReverse (int *tab, size_t n, double distValue) {

    generateSortedReverse(tab, n);
    makeDistortions(tab, n, distValue);

}

void generate (int *tab, int n, int genType) {

    switch (genType) {
        case 0:
            generateRandom(tab, n, n/10);
            break;
        case 1:
            generateRandom(tab, n, n*10);
            break;
        case 2:
            generateSorted(tab, n);
            break;
        case 3:
            generateAlmostSorted(tab, n, 0.025);
            break;
        case 4:
            generateAlmostSorted(tab, n, 0.25);
            break;
        case 5:
            generateAlmostSortedReverse(tab, n, 0.25);
            break;
        case 6:
            generateAlmostSortedReverse(tab, n, 0.025);
            break;
        case 7:
            generateSortedReverse(tab, n);
            break;
    }

}


/* Quick sort functions */

int partition (int *tab, int start, int end) {

    int pivot = tab[end];
    int i = start - 1;
    
    for (int j = start; j < end; j++) {
        if (tab[j] <= pivot) swap(&tab[j], &tab[++i]);
    }

    swap(&tab[end], &tab[++i]);
    
    return i;

}

int randPartition (int *tab, int start, int end) {

    int r = lrand48() % (end - start + 1) + start;
    swap (&tab[end], &tab[r]);
    return partition(tab, start, end);

}

int medianOfThree (int *tab, int a, int b, int c) {

    int r;
    if (tab[a] > tab[b]) {
        if (tab[b] > tab[c]) r = b;
        else if (tab[a] > tab[c]) r = c;
        else r = a;
    } else {
        if (tab[a] > tab[c]) r = a;
        else if (tab[b] > tab[c]) r = c;
        else r = b;
    }

    return r;

}

int rand3Partition (int *tab, int start, int end) {

    if (end - start < 2) return randPartition(tab, start,end);
    else {
        int a = lrand48() % (end - start + 1) + start;
        int b; int c;
        do { b = lrand48() % (end - start + 1) + start; } while (b == a);
        do { c = lrand48() % (end - start + 1) + start; } while (c == a || c == b);

        int r = medianOfThree(tab, a, b, c);
        swap (&tab[end], &tab[r]);
        return partition(tab, start, end);
    }
}

void insertionSort (int *tab, int start, int end) {

    int x; int j;
    for (int i = start+1; i <= end; i++) {
        x = tab[i];
        for (j = i-1; j >= start && tab[j] > x; j--) tab[j+1] = tab[j];
        tab[j+1] = x;
    }

}

void classicQuickSort (int *tab, int start, int end) {

    if (start < end) {
        int pivot = partition(tab, start, end);
        classicQuickSort(tab, start, pivot - 1);
        classicQuickSort(tab, pivot + 1, end);
    }

}

void randomizedQuickSort (int *tab, int start, int end) {

    if (start < end) {
        int pivot = randPartition(tab, start, end);
        randomizedQuickSort(tab, start, pivot - 1);
        randomizedQuickSort(tab, pivot + 1, end);
    }

}

void medianOfThreeQuickSort (int *tab, int start, int end) {

    if (start < end) {
        int pivot = rand3Partition(tab, start, end);
        medianOfThreeQuickSort(tab, start, pivot - 1);
        medianOfThreeQuickSort(tab, pivot + 1, end);
    }

}

void medianOfThreeQuickSortWithInsertionSort (int *tab, int start, int end) {

    if (end - start <= 10) {     // 10 is more less the value that is optimal to switch to insertionSort
        insertionSort(tab, start, end);
    } else if (start < end) {
        int pivot = rand3Partition(tab, start, end);
        medianOfThreeQuickSortWithInsertionSort(tab, start, pivot - 1);
        medianOfThreeQuickSortWithInsertionSort(tab, pivot + 1, end);
    }

}

void quickSort (int *tab, size_t n, int type) {

    int start = 0;
    int end = n-1;
    
    switch (type) {
        case 0:
            classicQuickSort(tab, start, end);
            break;
        case 1:
            randomizedQuickSort(tab, start, end);
            break;
        case 2:
            medianOfThreeQuickSort(tab, start, end);
            break;
        case 3:
            medianOfThreeQuickSortWithInsertionSort(tab, start, end);
            break;
        case 4:
            qsort(tab, n, sizeof(int), qsortCompare);
            break;
        default:
            printf("Quick sort switch case error");
            break;
    }
    
}


/* Time tester */

double timeTest (int *tab, size_t n, int type) {

    clock_t t0; clock_t t1;

    t0 = clock();
    while (t0 == (t1 = clock()));

    t0 = t1;
    quickSort(tab, n, type);
    t1 = clock();

    return (t1 - t0) * (1.0 / CLOCKS_PER_SEC);

}


/* Save functions */

void saveHeadline() {

    FILE *fp;
    if ((fp = fopen(FILENAME, "a")) == NULL) {
        printf("File open error");
        exit(1);
    }

    fprintf(fp, "generation method;n");
    for (int i = 0; i < 5; i++) fprintf(fp, ";%s", quickSortTypeDescription[i]);
    fclose(fp);

}

void saveDescription(int genType, int n) {

    FILE *fp;
    if ((fp = fopen(FILENAME, "a")) == NULL) {
        printf("File open error");
        exit(1);
    }
    
    fprintf(fp, "\n%s;%d;", generateMethodDescription[genType], n);
    fclose(fp);

}

void saveResults (double sec, int n, int qsortType, int genType) {

    FILE *fp;
    if ((fp=fopen(FILENAME, "a")) == NULL) {
        printf("File open error");
        exit(1);
    }

    fprintf(fp, "%lf;", sec);
    fclose(fp);

}

void saveToFile () {

    saveHeadline();

    for (int genType = 0; genType < 8; genType++) {
        for (int n = 10; n <= 100000; n *= 10) {
            int *tab = malloc (n * sizeof(int));
            
            saveDescription(genType, n);

            for (int qsortType = 0; qsortType < 5; qsortType++) {
                generate(tab, n, genType);
                saveResults(timeTest(tab, n, qsortType), n, qsortType, genType);
            }
            
            free(tab);
        }
    }

}

int main (void) {

    saveToFile();

    return 0;

}