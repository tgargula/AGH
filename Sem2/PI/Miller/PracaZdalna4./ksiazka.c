#include <stdio.h>

const int AUTOR_MAX = 50;
const int TYTUL_MAX = 50;

struct book {
    char *name;
    char *title;
    int yearOfPublication;
    double price;
};

void printBookInfo(struct book book1) {
    printf("Autor: %s\nTytul: %s\nRok wydania: %d\nCena: %.2lf PLN\n", book1.name, book1.title, book1.yearOfPublication, book1.price);
}

int main() {
    struct book book1 = {"J. R. R. Tolkien", "The Lord of the Rings: The Fellowship of the Ring", 1954, 71.99};
    printBookInfo(book1);
    return 0;
}