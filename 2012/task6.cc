#include <stdio.h>
#include <string.h>
#include <math.h>


int count(char *s1, char *s2) {
    int c = 0;
    while (s1[c] == s2[c] && s1[c] != 0) {
        c++;
    }
    return c;
}

int main(void) {
    char input[10000];
    scanf("%s", input);
    int s = 0;
    int total = 0;
    while (input[s] != 0) {
        total += count(input, input + s);
        s++;
    }
    printf("%d", total);
}
