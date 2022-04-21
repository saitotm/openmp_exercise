#include <algorithm>
#include <cstddef>
#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <vector>

#define NUM 50000000

double matrix_product(int size, std::vector<double> v, std::vector<double> w) {
    std::vector<double> dot_vec(size);
#pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        dot_vec[i] = v[i] * w[i];
    }

    double dot = 0;
#pragma omp parallel for reduction(+ : dot)
    for (int i = 0; i < size; ++i) {
        dot += dot_vec[i];
    }

    return dot;
}

int main(int argc, char *argv[]) {
    std::vector<double> v(NUM, 1);
    std::vector<double> w(NUM, 2);
    std::vector<double> dot_vec(NUM);

    double dot = matrix_product(NUM, v, w);
    printf("%f\n", dot);

    return 0;
}
