#ifndef TP_C_HW2_PARALLEL_LIB_H
#define TP_C_HW2_PARALLEL_LIB_H

void parallel_fill_array(int n);
void* threadFunc(void* thread_data);

typedef struct{
    int *array;
    int start;
    int end;
    int is_last_thread;
} pthrData;

#endif  // TP_C_HW2_PARALLEL_LIB_H
