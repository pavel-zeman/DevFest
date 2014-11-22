#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


long long int power(long long int a, long long int p) {
    long long int temp = a;
    long long int result = 1;
    while (p > 0) {
        if ((p & 1) == 1) result = result * temp;
        temp = temp * temp;
        p >>= 1;
    }
    return result;
}

int main(void) {
    int t;
    scanf("%d", &t);
    FOR(tt, t) {
        long long int n;
        scanf("%lld", &n);

        long long int p = power(2, (n + 1) / 2 + 1) - 2;
        if ((n & 1) == 0) p++;
        printf("Case #%d: %lld\n", tt + 1, p);
    }
}
