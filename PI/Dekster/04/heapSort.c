// Heap structure:
//
// heap[0] – current size of the heap
// heap[1..n] – actual heap

#include <stdio.h>
#include <stdlib.h>

inline void getTab (int *tab, size_t n) {
    
    for (int i = 0; i < n; i++) scanf("%d", &tab[i+1]);

}

inline void printTab (int *tab, size_t n) {

    for (int i = 0; i < n; i++) printf("%d\n", tab[i+1]);

}

inline int parent (int i) { return i / 2; }

inline int left (int i) { return 2 * i; }

inline int right (int i) { return 2 * i + 1; }

inline int sizeOfHeap (int *heap) { return heap[0]; }

void swap (int *a, int *b) {
    
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

void heapify (int *heap, int i) {

    size_t size = sizeOfHeap(heap);
    int l = left(i);
    int r = right(i);
    int largest;

    if (l <= size && heap[l] > heap[i]) largest = l;
    else largest = i;
    
    if (r <= size && heap[r] > heap[largest]) largest = r;
    
    if (largest != i) { 
        swap(&heap[i], &heap[largest]);
        heapify(heap, largest);
    }

}

void buildHeap (int *heap) {

    for (int i = sizeOfHeap(heap)/2; i > 0; i--) heapify(heap, i);

}

void swapMaxAndHeapify (int *heap) {

    swap(&heap[1], &heap[heap[0]--]);
    heapify(heap, 1);

}

void heapSort (int *heap) {
    
    buildHeap(heap);
    while (heap[0]) swapMaxAndHeapify(heap);

}
 
int main (void) {
    
    int Z;
    scanf("%d", &Z);

	while (Z--) {
		int n;
		scanf("%d", &n);
		
        int *tab = malloc ((n+1) * sizeof(int));
        tab[0] = n;

        getTab(tab, n);
        heapSort(tab);
        printTab(tab, n);
        
        free(tab);
    }

    return 0;

}