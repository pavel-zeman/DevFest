#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)



long long int coordinates[4][2];
int directions[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

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

void swap(long long int *a, long long int *b) {
    long long int t = *a;
    *a = *b;
    *b = t;
}

long long int sub(long long int value, long long int n) {
    if (value >= 0 && value < n) return 0;
    if (value < 0) return -value;
    if (value >= n) return value - n + 1;
    printf("Error");
    exit(1);
}

long long int calc(long long int x1, long long int y1, long long int x2, long long int y2, long long int n) {
    if (x1 > x2) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    long long int length = x2 - x1 + 1 - sub(x1, n) - sub(x2, n) - sub(y1, n) - sub(y2, n);
    if (length < 0) length = 0;
    return length;
}

int check(long long int x1, long long int y1, long long int n) {
    return x1 < 0 || y1 < 0 || x1 >= n || y1 >= n ? 0 : 1;
}

int main(void) {
    int t = getInt();
    FOR(tt, t) {
        long long int n = getInt(), x = getInt() - 1, y = getInt() - 1, c = getInt();
        FOR(i, 4) coordinates[i][0] = x, coordinates[i][1] = y;
        long long int used = 1;
        int steps = 0;

        while (used < c) {
            FOR(i, 4) coordinates[i][0] += directions[i][0], coordinates[i][1] += directions[i][1];
            FOR(i, 4) {
                int b = (i + 1) & 3;
                used += calc(coordinates[i][0], coordinates[i][1], coordinates[b][0], coordinates[b][1], n);
                used -= check(coordinates[i][0], coordinates[i][1], n);
            }
            steps++;
            //printf("%d %lld\n", steps, used);
        }

        printf("Case #%d: %d\n", tt + 1, steps);
    }
}
