#include <gtest/gtest.h>

extern "C" {
#include "consistent.h"
#include "parallel.h"
}

#define STRESS_ITERATION_NUMBER 30
#define STRESS_LIMIT_SIZE 10000

TEST(TestStressForParallelAndConsistent, RandomArraySize) {

    for(int i = 0; i < STRESS_ITERATION_NUMBER; i++) {
        int array_size = (rand() % STRESS_LIMIT_SIZE) + 1;
        int cpu_num = (rand() % array_size) + 1;
        int *parallel_array = parallel_fill_array(array_size, cpu_num);
        int *consistent_array = consistent_fill_array(array_size);

        for(int j = 0; j < array_size; j++) {
            EXPECT_EQ(parallel_array[j], consistent_array[j]);
        }

        free(parallel_array);
        free(consistent_array);
    }

}