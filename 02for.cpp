#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;

#pragma omp parallel num_threads(2)
    {
#pragma omp for
        for (i = 0; i < 10; i++) {
            b[i] = a[i];
        }
    }

    for (i = 0; i < 10; ++i) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    return 0;
}
