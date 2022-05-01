#include <iostream>
#include <new>
#include <sys/resource.h>
#include <cassert>

int cmp(int a, int b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    }

    return 0;
}

bool check(int *array, std::size_t size) {
    for (std::size_t i = 0; i < size - 1; ++i) {
        if (cmp(array[i], array[i + 1]) == 1) {
            return false;
        }
    }

    return true;
}

void print_array(int *array, int size) {
    printf("[ ");
    for (int i = 0; i < size; ++i) {
        printf("%d, ", array[i]);
    }
    printf("]");
}

void merge(int *out, const int *a, const int *b, std::size_t size_a, std::size_t size_b) {
    std::size_t size_out = size_a + size_b;
    std::size_t idx_a = 0;
    std::size_t idx_b = 0;

    for (std::size_t i = 0; i < size_out; ++i) {

        if (idx_a >= size_a) {
            out[i] = b[idx_b];
            idx_b++;
            continue;
        }

        if (idx_b >= size_b) {
            out[i] = a[idx_a];
            idx_a++;
            continue;
        }

        int c = cmp(a[idx_a], b[idx_b]);
        if (c == -1) {
            out[i] = a[idx_a];
            idx_a++;
        } else if (c == 1) {
            out[i] = b[idx_b];
            idx_b++;
        } else {
            out[i] = a[idx_a];
            idx_a++;
        }
    }
}

void merge_sort(int *out, const int *array, std::size_t size) {
    assert(size > 0);

    if (size == 1) {
        out[0] = array[0];
        return;
    }

    std::size_t size_a = size / 2;
    std::size_t size_b = size - size_a;
    const int *a = array;
    const int *b = array + size_a;

    assert(size_a > 0);
    assert(size_b > 0);

    int *out_a = new int[size_a];
    int *out_b = new int[size_b];

    merge_sort(out_a, a, size_a);
    assert(check(out_a, size_a));

    merge_sort(out_b, b, size_b);
    assert(check(out_b, size_b));

    merge(out, out_a, out_b, size_a, size_b);

    delete[] out_a;
    delete[] out_b;
}

const int array_size = 9;

int main(int argc, char *argv[]) {
    int array[array_size] = {3, 4, 2, 1, 9, 10, 21, -3, 10};
    int *out = new int[array_size];
    merge_sort(out, array, array_size);

    bool is_ok = check(out, array_size);

    if (is_ok) {
        printf("OK\n");
        print_array(out, array_size);
        printf("\n");
    } else {
        printf("Error\n");
        print_array(out, array_size);
        printf("\n");
    }

    return 0;
}
