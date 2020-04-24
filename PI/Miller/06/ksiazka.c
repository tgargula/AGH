#include <stdio.h>

typedef struct Book {
    char *name;
    char *title;
    int yearOfPublication;
    double price;
} Book;

void printBookInfo(Book book1) {
    printf("Autor: %s\nTytul: %s\nRok wydania: %d\nCena: %.2lf PLN\n", book1.name, book1.title, book1.yearOfPublication, book1.price);
}

int main() {
    Book book1 = {"J. R. R. Tolkien", "The Lord of the Rings: The Fellowship of the Ring", 1954, 71.99};
    printBookInfo(book1);
    return 0;
}