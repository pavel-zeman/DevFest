#include <stdio.h>
#include <string.h>


int primes[10000];
int primesCount;

int main(void) {
    primesCount = 1;
    primes[0] = 2;
    for (int i=3;i<10000;i++) {
        int j = 0;
        bool found = true;
        while (j < primesCount && primes[j] * primes[j] <= i) {
            if (i % primes[j] == 0) {
                found = false;
                break;
            }
            j++;
        }
        if (found) {
            primes[primesCount++] = i;
        }
    }
    for (int i=0;i<primesCount;i++) {
        if (primes[i] > 10) {
            char orig[100];
            sprintf(orig, "%d", primes[i]);
            bool found = false;
            for (int j =0; j<i;j++) {
                if (primes[j] > 10) {
                    char news[100];
                    sprintf(news, "%d", primes[j]);
                    if (strstr(orig, news)) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                printf("%d\n", primes[i]);
            }
        }
    }
}
