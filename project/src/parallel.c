#include <stdlib.h>
#include <pthread.h>
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
    if (n % 2 != 0) {
        n = n + 1;
    }

    int* array = calloc(INT_NUMBER, sizeof(int));

    pthread_t* threads = (pthread_t*) malloc(n * sizeof(pthread_t));
    pthrData* threadData = (pthrData*) malloc(n * sizeof(pthrData));

    int separator = 0;
    for(int i = 0; i < n; i++){
        threadData[i].array = array;
        threadData[i].start = separator;

        separator = separator + (INT_NUMBER / n);

        if (n == i - 1 && n % 2 == 0) { // check if array is nechetnyi and it's about last tread we must be careful about END variable
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

}
