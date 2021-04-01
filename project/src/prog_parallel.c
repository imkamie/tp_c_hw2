#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "prog.h"
#include "fill_array.h"

typedef struct {
    int *array;
    int start;
    int end;
    int is_last_thread;
} pthr_data_t;

void* thread_func(void* thread_data) {
    pthr_data_t *data = (pthr_data_t*) thread_data;

    data->array = fill_array(data->array, data->start, data->end);

    return NULL;
}

size_t new_threads_number(size_t array_size, size_t threads_num, size_t parts_num) {
    size_t numbers_of_extra_cells = array_size % threads_num;

    size_t numbers_of_additional_threads = 0;
    if (numbers_of_extra_cells % parts_num == 0) {
        numbers_of_additional_threads = numbers_of_extra_cells / parts_num;
    } else {
        numbers_of_additional_threads = (numbers_of_extra_cells / parts_num) + 1;
    }

    size_t new_numbers_of_threads = threads_num + numbers_of_additional_threads;

    return new_numbers_of_threads;
}



int* run_program(size_t array_size) {
    size_t number_of_threads = sysconf(_SC_NPROCESSORS_ONLN);
    size_t numbers_of_zone_for_each_thread = array_size / number_of_threads;
    size_t new_numbers_of_threads = number_of_threads;

    if (array_size % number_of_threads != 0) {
        new_numbers_of_threads = new_threads_number(array_size,
                                                    number_of_threads,
                                                    numbers_of_zone_for_each_thread);
    }

    if (new_numbers_of_threads > array_size) {
        return NULL;
    }

    int* array = calloc(array_size, sizeof(int));
    if (!array) {
        return NULL;
    }

    pthread_t* threads = malloc(new_numbers_of_threads * sizeof(pthread_t));
    if (!threads) {
        free(array);
        return NULL;
    }

    pthr_data_t* threadData = malloc(new_numbers_of_threads * sizeof(pthr_data_t));
    if (!threadData) {
        free(array);
        free(threads);
        return NULL;
    }

    size_t separator = 0;
    for (int i = 0; i < new_numbers_of_threads; i++) {
        if (i == new_numbers_of_threads - 1) {
            threadData[i].is_last_thread = 1;
        } else {
            threadData[i].is_last_thread = 0;
        }
        threadData[i].array = array;
        threadData[i].start = separator;

        separator = separator + numbers_of_zone_for_each_thread;

        if (i == new_numbers_of_threads - 1 && array_size % number_of_threads != 0) {
            threadData[i].end = array_size;
        } else {
            threadData[i].end = separator;
        }

        if (pthread_create(&(threads[i]), NULL, thread_func, &threadData[i]) != 0) {
            free(array);
            free(threads);
            free(threadData);
            return NULL;
        }
    }

    for (size_t i = 0; i < new_numbers_of_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            free(array);
            free(threads);
            free(threadData);
            return NULL;
        }
    }

    free(threads);
    free(threadData);

    return array;
}
