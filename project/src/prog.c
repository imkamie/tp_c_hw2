#include <stdlib.h>

#include "prog.h"
#include "fill_array.h"

int* run_program(size_t array_size) {
    int* array = calloc(array_size, sizeof(int));
    if (!array) {
        return NULL;
    }

    array = fill_array(array, 0, array_size);

    return array;
}
