#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MOD 1000000007
#define MSIZE (4 * sizeof(long long int))

char c = 0;
long long int getInt() {
    long long int r = 0;
    while (!(c >= '0' && c <= '9')) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}


long long int startMatrix[2][2] = {{1, 1}, {1, 0}};
long long int unitMatrix[2][2] = {{1, 0}, {0, 1}};

void mult(long long int m1[2][2], long long int m2[2][2]) {
    long long int result[2][2];

    result[0][0] = (m1[0][0] * m2[0][0] % MOD + m1[0][1] * m2[1][0] % MOD) % MOD;
    result[0][1] = (m1[0][0] * m2[0][1] % MOD + m1[0][1] * m2[1][1] % MOD) % MOD;
    result[1][1] = (m1[1][0] * m2[0][1] % MOD + m1[1][1] * m2[1][1] % MOD) % MOD;
    result[1][0] = (m1[1][0] * m2[0][0] % MOD + m1[1][1] * m2[1][0] % MOD) % MOD;

    memcpy(m1, result, MSIZE);
}

void print(long long int a[2][2]) {
    printf("%lld %lld %lld %lld  ", a[0][0], a[0][1], a[1][0], a[1][1]);
}

int main(void) {
    int t = getInt();
    FOR(tt, t) {
        long long int n = getInt();
        long long int currentMatrix[2][2];
        long long int squareMatrix[2][2];
        memcpy(currentMatrix, unitMatrix, MSIZE);
        memcpy(squareMatrix, startMatrix, MSIZE);

        n++;
        while (n > 0) {
            if ((n & 1) == 1) mult(currentMatrix, squareMatrix);
            n >>= 1;
            mult(squareMatrix, squareMatrix);
            //print(squareMatrix);
        }


        printf("Case #%d: %lld\n", tt + 1, currentMatrix[0][1]);
    }
}
