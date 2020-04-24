#include <stdio.h>

int aLetters(char *months[]) {
    int result = 0, i = 0, j = 0;
    // printf("OK\n");
    while(i < 12) {
        while(*(*(months + i) + j) != '\0') {
            // printf("%d %d\n", i, j);
            // printf("%c\n", *(*(months + i) + j));
            if(*(*(months + i) + j) == 'a') result += 1;
            j += 1;
        }
        i += 1; j = 0;
    }
    return result;
}

int aLetters2(char months[12][12]) {
    int result = 0, i = 0, j = 0;
    while(i < 12) {
        while(months[i][j] != '\0') {
            if(months[i][j] == 'a') result += 1;
            j += 1;
        }
        i += 1;
        j = 0;
    }
    return result;
}

int main() {
    char *monthsPtr[12] = {"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};
    char months[12][12] = {"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};
    // char **monthsPtr2 = months;
    printf("%d\n", aLetters2(months));
    printf("%d\n", aLetters(monthsPtr));
    return 0;
}