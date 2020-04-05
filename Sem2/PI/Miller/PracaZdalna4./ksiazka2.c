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
    book book1;
    fgets(bookName, AUTOR_MAX, stdin); fgets(bookTitle, TYTUL_MAX, stdin);
    book1.name = bookName; book1.title = bookTitle;
    scanf("%d %lf", &(book1.yearOfPublication), &(book1.price));
    return book1;
}

book *inputBookDataV2(book *book2) {
    char *bookName[AUTOR_MAX], *bookTitle[TYTUL_MAX];
    fgets(bookName, AUTOR_MAX, stdin); fgets(bookTitle, TYTUL_MAX, stdin);
    book2->name = bookName; book2->title = bookTitle;
    scanf("%d %lf", &(book2->yearOfPublication), &(book2->price));
    return book2;
}

void printBookInfo(book book1) {
    printf("Autor: %sTytul: %sRok wydania: %d\nCena: %.2lf PLN\n", book1.name, book1.title, book1.yearOfPublication, book1.price);
}

int main() {
    book book1 = inputBookData(); // {"J. R. R. Tolkien", "The Lord of the Rings: The Fellowship of the Ring", 1954, 71.99};
    printBookInfo(book1);
    book book2;
    inputBookDataV2(&book2);
    printBookInfo(book2);
    return 0;
}