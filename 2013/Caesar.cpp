#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

char c = 0;
int getInt() {
    int r = 0;
    while (!(c >= '0' && c <= '9')) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}

int main(void) {
    int t;
    scanf("%d", &t);
    FOR(tt, t) {
        char data[100];
        scanf("%s", data);
        char *a = data;
        while (*a) {
            *a = ((*a - 'a') + 3) % 26 + 'a';
            a++;
        }
        printf("Case #%d: %s\n", tt + 1, data);
    }
}
