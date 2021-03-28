#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "parallel.h"

void* threadFunc(void* thread_data) {
    pthrData *data = (pthrData*) thread_data;

    for (int i = data->start; i < data->end; i++) {
        data->array[i] = i % 4;
    }

    return NULL;
}

int* parallel_fill_array(int array_size, int old_numbers_of_threads) {
    int numbers_of_zone_for_each_thread = array_size / old_numbers_of_threads;
    int new_numbers_of_threads = old_numbers_of_threads;
    if (array_size % old_numbers_of_threads != 0) {
        int numbers_of_extra_cells = array_size % old_numbers_of_threads;

        int numbers_of_additional_threads = 0;
        if (numbers_of_extra_cells % numbers_of_zone_for_each_thread == 0) {
            numbers_of_additional_threads = numbers_of_extra_cells / numbers_of_zone_for_each_thread;
        } else {
            numbers_of_additional_threads = (numbers_of_extra_cells / numbers_of_zone_for_each_thread) + 1;
        }

        new_numbers_of_threads = old_numbers_of_threads + numbers_of_additional_threads;
    }

    if (new_numbers_of_threads > array_size) {
        printf("The number of threads is bigger than the size of the array\n");
        return NULL;
    }

    int* array = calloc(array_size, sizeof(int));

    pthread_t* threads = (pthread_t*) malloc(new_numbers_of_threads * sizeof(pthread_t));
    pthrData* threadData = (pthrData*) malloc(new_numbers_of_threads * sizeof(pthrData));

    int separator = 0;
    for (int i = 0; i < new_numbers_of_threads; i++) {
        if (i == new_numbers_of_threads - 1) {
            threadData[i].is_last_thread = 1;
        } else {
            threadData[i].is_last_thread = 0;
        }
        threadData[i].array = array;
        threadData[i].start = separator;

        separator = separator + numbers_of_zone_for_each_thread;

        if (i == new_numbers_of_threads - 1 && array_size % old_numbers_of_threads != 0) {
            threadData[i].end = array_size;
        } else {
            threadData[i].end = separator;
        }
        pthread_create(&(threads[i]), NULL, threadFunc, &threadData[i]);
    }

    for (int i = 0; i < new_numbers_of_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
    free(threadData);

    return array;
}
