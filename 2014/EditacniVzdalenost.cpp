#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


#define MAX_L 200

char p[MAX_L];
char q[MAX_L];

int minD[MAX_L][MAX_L];

int dist(int i, int j) {
    if (minD[i][j] < 0) {
        int result;
        if (i == 0 || j == 0) result = i + j;
        else {
            result = dist(i - 1, j) + 1;
            int temp = dist(i, j - 1) + 1;
            if (temp < result) result = temp;
            temp = dist(i - 1, j - 1) + (p[i - 1] == q[j - 1] ? 0 : 1);
            if (temp < result) result = temp;
        }
        minD[i][j] = result;
    }
    return minD[i][j];
}

int main(void) {
    int t;
    scanf("%d", &t);
    FOR(tt, t) {
        scanf("%s %s", p, q);
        int l1 = strlen(p);
        int l2 = strlen(q);
        FOR(i, l1 + 1) FOR(j, l2 + 1) minD[i][j] = -1;
        printf("Case #%d: %d\n", tt + 1, dist(l1, l2));
    }
}
