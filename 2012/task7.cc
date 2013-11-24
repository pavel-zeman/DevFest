#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void) {
    char input[1000];
    scanf("%s", input);
    int c = 1;
    while (input[c] != 0) {
        printf("%c", input[c]);
        c++;
        if (input[c] == 0) break;
        c++;
    }
}
