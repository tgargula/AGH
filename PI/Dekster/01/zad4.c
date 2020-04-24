// Caesar cipher

#include <stdio.h>

int main(void) {
    char str[20];
    int k;
    scanf("%s", str);
    scanf("%d", &k);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] + k > 'z') str[i] = str[i] - ('z'-'a'+1) + k;
        else str[i] += k;
    }
    printf("%s\n", str);
    return 0;
}