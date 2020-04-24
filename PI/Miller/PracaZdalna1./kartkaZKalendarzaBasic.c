#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int monthDays(int month) {
    if(month == 2) return 28;       // Not leap year
    month = month % 7;
    if(month % 2 == 0) return 30;
    else return 31;
}

void printMonth(int month, int firstDay) {
    if(firstDay > 6) firstDay = firstDay % 7;
    if(month > 12) month = month % 12 + 1;
    printf("Miesiac %d\n%s\n", month, "|Ni |Po |Wt |Sr |Cz |Pt |So |");
    for(int i = 0; i < firstDay; i++) printf("|   ");
    for(int day = 1; day <= monthDays(month); day++) {
        printf("|%2d ", day);
        if(( day + firstDay ) % 7 == 0 ) printf("|\n");
    }
    printf("%c", '\n');
}

int main() {
    int month, firstDay;
    scanf("%d %d", &month, &firstDay);
    printMonth(month, firstDay);
    return 0;
}