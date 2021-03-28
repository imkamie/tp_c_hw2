#ifndef PROJECT_INCLUDE_PARALLEL_H_
#define PROJECT_INCLUDE_PARALLEL_H_

void parallel_fill_array(int array_size, int cpu_num);
void* threadFunc(void* thread_data);

typedef struct {
    int *array;
    int start;
    int end;
    int is_last_thread;
} pthrData;

#endif  // PROJECT_INCLUDE_PARALLEL_H_
