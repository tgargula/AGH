/// Funkcje do implementacji tablicy rzadkiej

#include <iostream>

using namespace std;

struct node {
    int v;
    node *next;
};

void init (node *&tab) {
    // nie wiem, o co dokładnie chodzi, pomóżcie xd
}

int value (node *tab, int n) {
    int i = 0;
    while (tab->next != NULL and i < n) {
        i++;
        tab = tab->next;
    }
    if ( i == n ) return tab->v;
    else return -1;
}

void set (node *&tab, int n, int value) {
    int i = 0;
    while ( tab->next != NULL and i < n ) {
        i++;
        tab = tab->next; //imo tab powinno caly czas wskazywac na pierwszy element a tu bym zrobil kopie i szedl kopia po elementach az do n
    }
    if ( i == n ) tab->v = value;
}



int main() {
    return 0;
}
