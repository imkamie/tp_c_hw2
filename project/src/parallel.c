#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "parallel.h"

#define INT_NUMBER 26214400


void* threadFunc(void* thread_data) {
    //получаем структуру с данными
    pthrData *data = (pthrData*) thread_data;

    //складываем элементы строк матриц и сохраняем результат
    for(int i = data->start; i < data->end; i++) {
        data->array[i] = i % 4;

    }
    return NULL;
}

void parallel_fill_array(int n) {
    if (INT_NUMBER % n != 0) { // if size of array doesn't divide without a remainder
//        n = n + 1;
        int numbers_of_extra_cells = INT_NUMBER % n;
        int numbers_of_zone_for_each_thread = INT_NUMBER / n;


        int numbers_of_additional_threads = 0;
        if (numbers_of_extra_cells % numbers_of_zone_for_each_thread == 0) {
            numbers_of_additional_threads = numbers_of_extra_cells / numbers_of_zone_for_each_thread;
        } else {
            numbers_of_additional_threads = (numbers_of_extra_cells / numbers_of_zone_for_each_thread) + 1;
        }

        n = n + numbers_of_additional_threads;
    }

    if (n > INT_NUMBER) {
        printf("[ERROR] the number of threads is bigger than the size of the array\n");
        return;
    }

    int* array = calloc(INT_NUMBER, sizeof(int));

    pthread_t* threads = (pthread_t*) malloc(n * sizeof(pthread_t));
    pthrData* threadData = (pthrData*) malloc(n * sizeof(pthrData));

    int separator = 0;
    for(int i = 0; i < n; i++){
        if (i == n - 1) {
            threadData[i].is_last_thread = 1;
        } else {
            threadData[i].is_last_thread = 0;
        }
        threadData[i].array = array;
        threadData[i].start = separator;

        separator = separator + (INT_NUMBER / n);

        if (n == i - 1 && INT_NUMBER % n == 0) { // check if array is odd and it's about last tread we must be careful about END variable
            threadData[i].end = INT_NUMBER - 1;
        } else {
            threadData[i].end = separator;
        }
        pthread_create(&(threads[i]), NULL, threadFunc, &threadData[i]);
    }

    //ожидаем выполнение всех потоков
    for(int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    //освобождаем память
    free(threads);
    free(threadData);


    for (int i = 0; i < INT_NUMBER; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
}
