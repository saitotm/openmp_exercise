#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
#pragma omp parallel num_threads(10)
    { printf("Hello, World %d of %d\n", omp_get_thread_num(), omp_get_num_threads()); }
    return 0;
}
