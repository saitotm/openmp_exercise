#include <cstdio>

#define N 4096

void verify(const int n, const float *a, const float *b, const float *c);

int main(int argc, char *argv[]) {
    float a[N], b[N], c[N];
    int i;

#ifdef _OPENMP
    printf("OpneMP mode!\n\n");
#endif

    for (i = 0; i < N; ++i) {
        a[i] = (float)(i + 1000);
        b[i] = (float)i / 10.f;
    }

#pragma omp parallel for
    for (i = 0; i < N; ++i) {
        c[i] = a[i] * b[i];
    }

    printf("(a * b = c)\n");
    for (i = 0; i < 10; ++i) {
        printf("%f * %f = %f\n", a[i], b[i], c[i]);
    }

    verify(N, a, b, c);

    return 0;
}
