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

long long int fib[200];


int main(void) {
    fib[0] = 1;
    fib[1] = 1;
    FORE(i, 2, 200) fib[i] = fib[i - 1] + fib[i - 2];

    int t = getInt();
    FOR(tt, t) {
        int n = getInt();
        printf("Case #%d: %lld\n", tt + 1, fib[n]);
    }
}
