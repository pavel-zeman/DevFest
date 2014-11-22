#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_N 150002

int a[MAX_N];
int w[MAX_N];
long long int max[MAX_N];
int n;

int main(void) {
    int t;
    scanf("%d", &t);
    FOR(tt, t) {
        scanf("%d", &n);
        FOR(i, n) scanf("%d", &a[i]);
        FOR(i, n) scanf("%d", &w[i]);

        max[0] = w[0];
        FORE(i, 1, n) {
            int currentA = a[i];
            long long int currentMax = 0;
            FOR(j, i) if (a[j] < currentA && max[j] > currentMax) currentMax = max[j];
            max[i] = currentMax + w[i];
        }
        long long int total = 0;
        FOR(i, n) if (max[i] > total) total = max[i];

        printf("Case #%d: %lld\n", tt + 1, total);
    }
}
