#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Point {
    int row;
    int column;
} Point;

typedef struct Node {
    Point p;
    struct Node *next;
} Node;


/* Io functions */

inline void setInitialValues (int *n, int *k) { scanf("%d%d", n, k); }
void scanTable (int **tab, int n) { for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &tab[i][j]); }
inline void scanCommand (struct Point *p, int *colorCode) { scanf("%d%d%d", &p->row, &p->column, colorCode); }

void printTable (int **tab, int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", tab[i][j]);
        printf("\n");
    }

}


/* Queue functions */

inline bool isEmpty (Node *queue) { return queue->next == NULL; }

void push (Node *queue, Point p) {

    Node *node = (Node *) malloc (sizeof(Node));
    node->p.row = p.row;
    node->p.column = p.column;
    node->next = NULL;

    while (queue->next != NULL) queue = queue->next;
    queue->next = node;

}

Point pop (Node *queue) {

    Node *node = queue->next;
    queue->next = queue->next->next;
    Point p = node->p;
    free(node);

    return p;

}


/* Command execution */ 

inline bool isPainted (int **tab, Point p) { return tab[p.row][p.column] != 0; }
inline void paint (int **tab, Point p, int colorCode) { tab[p.row][p.column] = colorCode; }
inline bool isPossible (int n, Point p) { return p.row < n && p.row >= 0 && p.column < n && p.column >=0; }

void checkNeighbors (Node *queue, Point p, int **tab, int n) {

    Point up, right, down, left;
    up = right = down = left = p;
    up.row--; right.column++; down.row++; left.column--;

    if (isPossible(n, up)    && !isPainted(tab, up))    push(queue, up);
    if (isPossible(n, right) && !isPainted(tab, right)) push(queue, right);
    if (isPossible(n, down)  && !isPainted(tab, down))  push(queue, down);
    if (isPossible(n, left)  && !isPainted(tab, left))  push(queue, left);

}

void scanAndExecuteCommands (int **tab, int n, int k) {

    for (int i = 0; i < k; i++) {
        Point p;
        int colorCode;
        Node *queue = (Node *) malloc(sizeof(Node));
        queue->p.row = queue->p.column = -1; queue->next = NULL;

        scanCommand(&p, &colorCode);

        if (!isPainted(tab, p)) paint(tab, p, colorCode);
        checkNeighbors(queue, p, tab, n);

        while (!isEmpty(queue)) {
            Point curr = pop(queue);
            paint(tab, curr, colorCode);
            checkNeighbors(queue, curr, tab, n);
        }

    }

}


/* main */

int main(void) {

    int n; int k;
    setInitialValues(&n, &k);
    int **tab = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) tab[i] = malloc(n * sizeof(int));

    scanTable(tab, n);
    scanAndExecuteCommands(tab, n, k);
    printTable(tab, n);

    for (int i = 0; i < n; i++) free(tab[i]);
    free(tab);

    return 0;

}