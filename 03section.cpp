#include <omp.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            { printf("section0: %d of %d\n", omp_get_thread_num(), omp_get_num_threads()); }
#pragma omp section
            { printf("section0: %d of %d\n", omp_get_thread_num(), omp_get_num_threads()); }
#pragma omp section
            { printf("section0: %d of %d\n", omp_get_thread_num(), omp_get_num_threads()); }
        }
    }
    return 0;
}
