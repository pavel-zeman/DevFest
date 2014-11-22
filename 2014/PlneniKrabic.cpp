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
    int t = getInt();
    FOR(tt, t) {
        int n = getInt();
        int m = getInt();
        long long int total = 0;
        FOR(i, m) {
            int a = getInt();
            int b = getInt();
            long long int k = getInt();

            total += k * (b - a + 1);
        }
        printf("Case #%d: %lld\n", tt + 1, total / n);
    }
}
