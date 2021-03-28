#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "parallel.h"

void* threadFunc(void* thread_data) {
    // получаем структуру с данными
    pthrData *data = (pthrData*) thread_data;

    // складываем элементы строк матриц и сохраняем результат
    for (int i = data->start; i < data->end; i++) {
        data->array[i] = i % 4;
    }
    return NULL;
}

int* parallel_fill_array(int array_size, int cpu_num) {
    if (array_size % cpu_num != 0) {  // if size of array doesn't divide without a remainder
        int numbers_of_extra_cells = array_size % cpu_num;
        int numbers_of_zone_for_each_thread = array_size / cpu_num;

        int numbers_of_additional_threads = 0;
        if (numbers_of_extra_cells % numbers_of_zone_for_each_thread == 0) {
            numbers_of_additional_threads = numbers_of_extra_cells / numbers_of_zone_for_each_thread;
        } else {
            numbers_of_additional_threads = (numbers_of_extra_cells / numbers_of_zone_for_each_thread) + 1;
        }

        cpu_num = cpu_num + numbers_of_additional_threads;
    }

    if (cpu_num > array_size) {
        printf("[ERROR] the number of threads is bigger than the size of the array\n");
        return NULL;
    }

    int* array = calloc(array_size, sizeof(int));

    pthread_t* threads = (pthread_t*) malloc(cpu_num * sizeof(pthread_t));
    pthrData* threadData = (pthrData*) malloc(cpu_num * sizeof(pthrData));

    int separator = 0;
    for (int i = 0; i < cpu_num; i++) {
        if (i == cpu_num - 1) {
            threadData[i].is_last_thread = 1;
        } else {
            threadData[i].is_last_thread = 0;
        }
        threadData[i].array = array;
        threadData[i].start = separator;

        separator = separator + (array_size / cpu_num);

        if (cpu_num == i - 1 && array_size % cpu_num == 0) {
            threadData[i].end = array_size - 1;
        } else {
            threadData[i].end = separator;
        }
        pthread_create(&(threads[i]), NULL, threadFunc, &threadData[i]);
    }

    // ожидаем выполнение всех потоков
    for (int i = 0; i < cpu_num; i++) {
        pthread_join(threads[i], NULL);
    }

    // освобождаем память
    free(threads);
    free(threadData);

    return array;
}
