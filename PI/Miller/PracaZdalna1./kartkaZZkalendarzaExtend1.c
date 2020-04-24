#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main() {            // Does not work
    int monthToPrint;
    time_t currentTime = time(NULL);
    char* currentTimeString = ctime(&currentTime);
    printf("%s\n", currentTimeString);
    // char monthNames[12][12] = {"Styczen\0", "Luty\0", "Marzec\0", "Kwiecien\0", "Maj\0", "Czerwiec\0", "Lipiec\0", "Sierpien\0", "Wrzesien\0", "Pazdziernik\0", "Listopad\0", "Grudzien\0"};
    return 0;
}