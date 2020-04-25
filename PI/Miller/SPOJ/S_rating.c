// https://www.spoj.com/problems/RATING/

#include <stdio.h>
#define N 300000

struct person {     // DOES NOT WORK
    int rank1, rank2, orderRank1, orderRank2, startOrder;
};

void inputPersons(struct person persons[], int n);
void printer(struct person persons[], int n);
void merge(struct person tab[], int start, int middlePoint, int finish, int sortParam);
void mergeSortPersons(struct person tab[], int start, int finish, int sortParam);
void orderPersons(struct person persons[], int n, int rankNum);
int min(int a, int b);
void finallySolveProblem(struct person persons[], int n);

int main() {
    int n;
    scanf("%d", &n);
    struct person persons[n];
    inputPersons(persons, n);

    printer(persons, n);

    mergeSortPersons(persons, 0, n-1, 1);
    orderPersons(persons, n, 1);
    printf("%s\n", "1.");

    printer(persons, n);
    mergeSortPersons(persons, 0, n-1, 2);
    orderPersons(persons, n, 2);

    printf("%s\n", "2.");
    printer(persons, n);
    mergeSortPersons(persons, 0, n-1, 3);

    printf("%s\n", "3.");
    printer(persons, n);
    finallySolveProblem(persons, n);
    return 0;
}

void printer(struct person persons[], int n) {
    for(int i = 0; i < n; i += 1) {
        printf("%s %d %c", "startOrder = ", persons[i].startOrder, '\n');
        printf("%s %d %c", "rank1 = ", persons[i].rank1, '\n');
        printf("%s %d %c", "rank2 = ", persons[i].rank2, '\n');
        printf("%s %d %c", "orderRank1 = ", persons[i].orderRank1, '\n');
        printf("%s %d %c", "orderRank2 = ", persons[i].orderRank2, '\n');
        printf("%c", '\n');
    }
}

void inputPersons(struct person persons[], int n) {
    for(int i = 0; i < n; i+=1) {
        scanf("%d %d", &persons[i].rank1, &persons[i].rank2);
        persons[i].startOrder = i;
    }
}

void merge(struct person tab[], int start, int middlePoint, int finish, int sortParam) {
    int i, j, k;
    int t1Length = middlePoint - start + 1, t2Length = finish - start;
    struct person tab1[t1Length], tab2[t2Length];     // create arrays to storge temp data

    for(i = 0; i < t1Length; i+=1) tab1[i] = tab[start+i];      // copy data to arrays
    for(j = 0; j < t2Length; j+=1) tab2[j] = tab[middlePoint+1+j];

    i = j = 0; k = start;

    if(sortParam == 1) {
        while(i < t1Length && j < t2Length) {       // merge 
            if(tab1[i].rank1 <= tab2[j].rank1) {
                tab[k] = tab1[i]; i+=1;
            } else {
                tab[k] = tab2[j]; j+=1;
            }
                k+=1;
            }

        while(i < t1Length) {
            tab[k] = tab1[i]; i+=1; k+=1;
        }
        while(j < t2Length) {
            tab[k] = tab2[j]; j+=1; k+=1;
        }
    } else if(sortParam == 2) {
        while(i < t1Length && j < t2Length) {       // merge 
            if(tab1[i].rank2 <= tab2[j].rank2) {
                tab[k] = tab1[i]; i+=1;
            } else {
                tab[k] = tab2[j]; j+=1;
            }
                k+=1;
            }

        while(i < t1Length) {
            tab[k] = tab1[i]; i+=1; k+=1;
        }
        while(j < t2Length) {
            tab[k] = tab2[j]; j+=1; k+=1;
        }
    } else {
        while(i < t1Length && j < t2Length) {       // merge 
            if(tab1[i].startOrder <= tab2[j].startOrder) {
                tab[k] = tab1[i]; i+=1;
            } else {
                tab[k] = tab2[j]; j+=1;
            }
                k+=1;
            }

        while(i < t1Length) {
            tab[k] = tab1[i]; i+=1; k+=1;
        }
        while(j < t2Length) {
            tab[k] = tab2[j]; j+=1; k+=1;
        }
    }
}

void mergeSortPersons(struct person tab[], int start, int finish, int sortParam) {
    if(start < finish) {                            // make two halves
        int middlePoint = start + (finish - start) / 2;
        mergeSortPersons(tab, start, middlePoint, sortParam);
        mergeSortPersons(tab, middlePoint+1, finish, sortParam);

        merge(tab, start, (start+finish)/2, finish, sortParam);
    }
}

void orderPersons(struct person persons[], int n, int rankNum) {
    if(rankNum == 1) {
        for(int i = 0; i < n; i+=1) {
            persons[i].orderRank1 = i;
        }
    } else {
        for(int i = 0; i < n; i+=1) {
            persons[i].orderRank2 = i;
        }
    }   
}

int min(int a, int b) {
    if(a < b) return a;
    else return b;
}

void finallySolveProblem(struct person persons[], int n) {
    for(int i = 0; i < n; i += 1) {
        printf("%d\n", min(persons[i].orderRank1, persons[i].orderRank2));
    }
}