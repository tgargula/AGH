#include <stdio.h>
#include <stdlib.h>

const int AUTOR_MAX = 50;
const int TYTUL_MAX = 50;

typedef struct {
    char *name;
    char *title;
    int yearOfPublication;
    double price;
} book;

book inputBookData() {
    char *bookName[AUTOR_MAX], *bookTitle[TYTUL_MAX];
    book book1 = {"adf", "va", 0, 0.0};
    fgets(bookName, AUTOR_MAX, stdin); fgets(bookTitle, TYTUL_MAX, stdin);
    book1.name = bookName; book1.title = bookTitle;
    scanf("%d %lf", &(book1.yearOfPublication), &(book1.price));
    return book1;
}

void printBookInfo(book book1) {
    printf("Autor: %sTytul: %sRok wydania: %d\nCena: %.2lf PLN\n", book1.name, book1.title, book1.yearOfPublication, book1.price);
}

int main() {
    book book1 = inputBookData(); // {"J. R. R. Tolkien", "The Lord of the Rings: The Fellowship of the Ring", 1954, 71.99};
    printBookInfo(book1);
    return 0;
}