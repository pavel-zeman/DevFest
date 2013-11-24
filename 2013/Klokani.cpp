#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX 110

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

int result[MAX][MAX][MAX];


int calc(int a, int b, int c) {
    if (result[a][b][c] != -1) return result[a][b][c];
    int local = 0;
    if (b < c - 1) {
        FORE(i, b + 1, c) {
            int temp = calc(b, i, c) + 1;
            if (temp > local) local = temp;
        }
    }
    if (a < b - 1) {
        FORE(i, a + 1, b) {
            int temp = calc(a, i, b) + 1;
            if (temp > local) local = temp;
        }
    }
    result[a][b][c] = local;
    return local;
}

int main(void) {
    FOR(i, MAX) FOR(j, MAX) FOR(k, MAX) result[i][j][k] = -1;
    FOR(i, MAX) FORE(j, i + 1, MAX) FORE(k, j + 1, MAX) calc(i, j, k);


    int t = getInt();
    FOR(tt, t) {
        int a = getInt(), b = getInt(), c = getInt();
        printf("Case #%d: %d\n", tt + 1, result[a][b][c]);
    }
}
