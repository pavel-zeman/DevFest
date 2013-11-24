#include <stdio.h>
#include <string.h>
#include <math.h>


int n;
int x[1000];
int y[1000];



int main(void) {
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    x[n] = x[0];
    y[n] = y[0];
    double distance = 0;
    for (int i=0;i<n;i++) {
        double xd = x[i+1] - x[i];
        double yd = y[i+1] - y[i];
        xd = xd * 5;
        yd = yd * 5;
        distance += sqrt(xd * xd + yd * yd);
    }
    printf("%lf", distance);

}
