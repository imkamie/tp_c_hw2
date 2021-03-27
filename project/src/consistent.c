#include <stdlib.h>

#include "consistent.h"

#define INT_NUMBER 26214400

void consistent_fill_array() {
    int* array = calloc(INT_NUMBER, sizeof(int));

    for (int i = 0; i < INT_NUMBER; i++) {
        array[i] = i % 4;
    }
}
