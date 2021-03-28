#include <stdlib.h>

#include "consistent.h"

void consistent_fill_array(int array_size) {
    int* array = calloc(array_size, sizeof(int));

    for (int i = 0; i < array_size; i++) {
        array[i] = i % 4;
    }

    free(array);
}
