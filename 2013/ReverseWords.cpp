#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


#define MAX_L 10000

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
    char buf[MAX_L];
    gets(buf);
    int t = atoi(buf);
    FOR(tt, t) {
        gets(buf);

        char result[MAX_L];

        int end = strlen(buf);
        while (buf[end] < 32) end--;
        buf[++end] = 0;

        int start = end - 1;
        int resPos = 0;

        if (end > 0) {
            while (start >= 0) {
                while (start > 0 && buf[start] != ' ') start--;
                int s = start == 0 ? start : start + 1;
                buf[end] = 0;
                strcpy(result + resPos, buf + s);
                resPos += end - s;
                result[resPos++] = ' ';
                end = start;
                start = end - 1;
                result[resPos] = 0;
                //printf("AA: %s ", result);
            }
        } else {
            result[0] = 0;
        }
        if (resPos > 0) result[resPos - 1] = 0;
        printf("Case #%d: %s\n", tt + 1, result);
    }
}
