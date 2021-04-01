#include <gtest/gtest.h>
#include <cstdlib>
#include <random>

extern "C" {
#include "prog.h"
}

#define STRESS_ITERATION_NUMBER 10

TEST(TestStressForParallelAndConsistent, RandomArraySize) {
    for (int i = 0; i < STRESS_ITERATION_NUMBER; i++) {
        static std::mt19937::result_type rand;
        int array_size = rand;
        int *parallel_array = run_program(array_size);
        int *consistent_array = run_program(array_size);

        for (int j = 0; j < array_size; j++) {
            EXPECT_EQ(parallel_array[j], consistent_array[j]);
        }

        free(parallel_array);
        free(consistent_array);
    }
}
