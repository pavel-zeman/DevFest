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

char data[100000000];

int abs(int a) {
    return a < 0 ? -a : a;
}

int main(void) {
    int t;
    scanf("%d", &t);

    FOR(tt, t) {
        scanf("%s", data);
        int x = 0, y = 0;
        char *p = data;
        while (*p) {
            if (*p == 'x') x++; else y++;
            p++;
        }
        int size = abs(x - y);
        FOR(i, size) data[i] = x > y ? 'x' : 'y';
        data[size] = 0;
        printf("Case #%d: %s\n", tt + 1, data);
    }
}
