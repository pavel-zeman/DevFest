#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_P 20000

int p[MAX_P];

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


bool used[1000000];
char buf[100];
int valsTotal = 0;
int vals[1000000];

char * generateBin(int a, int bits) {
    FOR(i, bits) {
        buf[bits - i - 1] = (a & 1) ? '1' : '0';
        a >>= 1;
    }
    buf[bits] = 0;
    return buf;
}

void generate(int remain, int pos, int bits, int value) {
    if (remain == 0) {
        vals[valsTotal++] = value;
    } else {
        FORE(i, pos, bits) {
            generate(remain - 1, i + 1, bits, value | (1 << i));
        }
    }
}

void test(int a, int bits) {
    if (used[a]) return;
    used[a] = true;
    FOR(i, valsTotal) {
        test(a ^ vals[i], bits);
    }
}


int abs(int a) {
    return a < 0 ? -a : a;
}

int main(void) {
    /*int x = 5;
    int total = 1 << (2 * x - 1);
    FOR(i, total) used[i] = false;
    generate(x, 0, 2 * x - 1, 0);
    printf("Generated: %d\n", valsTotal);
    FOR(i, valsTotal) printf("%s\n", generateBin(vals[i], 2 * x - 1));
    printf("AAA\n");

    test(0, 2 * x - 1);

    int total2 = 0;
    FOR(i, total) {
        if (used[i]) {
            printf("%s\n", generateBin(i, 2 * x - 1));
            total2++;
        }
    }
    printf("Total %d\n", total2);*/


    int t;
    scanf("%d", &t);
    FOR(tt, t) {
        int n;
        scanf("%d", &n);
        FOR(i, 2 * n - 1) {
            scanf("%d", &p[i]);
        }

        int min = 100000;
        int total = 0;
        int numNegative = 0;
        FOR(i, 2 * n - 1) {
            total += abs(p[i]);
            if (abs(p[i]) < min) min = abs(p[i]);
            if (p[i] < 0) numNegative++;
        }

        if ((n & 1) == 1) {
            // nothing to do
        } else {
            if ((numNegative & 1) == 1) {
                total -= 2 * min;
            }
        }

        printf("Case #%d: %d\n", tt + 1, total);
    }
}
