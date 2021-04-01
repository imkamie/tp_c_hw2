#include <stddef.h>

#include "fill_array.h"

int* fill_array(int* array, int start, int end) {
    if (end <= start) {
        return NULL;
    }

    for (int i = start; i < end; i++) {
        array[i] = i % 4;
    }

    return array;
}

