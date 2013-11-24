#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 26

int distance[N][N];


int main(void) {
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) distance[i][j] = 0;
    while (1) {
        char first[100], second[100];
        scanf("%s", first);
        if (!strcmp(first, "xxx")) break;
        scanf("%s", second);
        scanf("%d", &distance[first[0] - 'A'][second[0] - 'A']);
    }

    for (int k=0;k<N;k++) {
        for (int i=0;i<N;i++)
            for (int j=0;j<N;j++)
                if (i != j && (distance[i][k] + distance[k][j] < distance[i][j] || distance[i][j] == 0) && distance[i][k] != 0 && distance[k][j] != 0)
                    distance[i][j] = distance[i][k] + distance[k][j];

        /*for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                printf("%d ", distance[i][j]);
            }
            printf("\n");
        }
        printf("\n");*/
    }
    int minMax = 0;
    int max = 1000000;
    for (int i=0;i<N;i++) {
        int localMax = 0;
        for (int j=0;j<N;j++)
            if (distance[i][j] > localMax) localMax = distance[i][j];
        printf("Local max: %d %d\n", i, localMax);
        if (localMax != 0) {
            if (localMax < max) {
                minMax = i;
                max = localMax;
            }
        }
    }
    printf("%c %d\n", minMax + 'A', max);
}
