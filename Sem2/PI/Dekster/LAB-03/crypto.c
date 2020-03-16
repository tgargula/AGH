#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define N 11	//	100 chars + nullbyte

void removeEndline (char *message) {

    int L = (int)strlen(message);
    if (message[L-1] == '\n') message[L-1] = 0;

}

int calculateShift (char *message) {

    int ctr = 0;
    while (message[ctr] != ' ' && message[ctr] != '\0' && ctr < N-1) ctr++; // the message cannot be larger than N-1

    return ctr;

}

inline bool isUppercase (char letter) { return letter <= 'Z'; } // uppercase letters have smaller ASCII id

void encryptLetter (char *message, int i, int k) {

    if (isUppercase(message[i])) message[i] = ((message[i] + k - 'A') % ('Z' - 'A' + 1)) + 'A';
    else message[i] = ((message[i] + k - 'a') % ('z' - 'a' + 1)) + 'a';

}

void encrypt (char *message) {

	int k = calculateShift(message);

    for (int i = 0; i < (int)strlen(message); i++) {

        if (message[i] != ' ') encryptLetter(message,i,k);
        
    }

}

int main (void) {

	char message[N];

	fgets(message, N, stdin);
    removeEndline(message);
	
    encrypt(message);

    printf("%s\n", message);

    return 0;

}