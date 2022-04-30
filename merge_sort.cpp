#include <iostream>
#include <sys/resource.h>

void merge_sort(int *array, int size) {
    // TODO: implement merge sort
}

int cmp(int a, int b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    }

    return 0;
}

bool check(int *array, int size) {
    for (int i = 0; i < size - 1; ++i) {
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

int main(int argc, char *argv[]) {
    int array[5] = {3, 4, 2, 1, 9};
    merge_sort(array, 5);

    bool is_ok = check(array, 5);

    if (is_ok) {
        printf("OK\n");
    } else {
        printf("Error\n");
        print_array(array, 5);
        printf("\n");
    }

    return 0;
}
