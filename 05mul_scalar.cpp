#include <stdio.h>
#include <stdlib.h>

#define n 10

int main(int argc, char *argv[]) {
    int i;
    float x[n], y[n];

    for (i = 0; i < n; ++i) {
        x[i] = (float)rand();
    }

    float a = (float)rand();

#pragma omp parallel for
    for (i = 0; i < n; ++i) {
        y[i] = a * x[i];
    }

    for (i = 0; i < n; ++i) {
        printf("y[%d] = %.10f\n", i, y[i]);
    }
    return 0;
}
