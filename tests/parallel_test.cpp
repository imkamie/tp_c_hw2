#include <gtest/gtest.h>

extern "C" {
#include "parallel.h"
}

TEST(TestConsistFillArray, ParallelFillArraysSizeAndNumberOfCpuSame) {
    int array_size = 4;
    int cpu_num = 4;
    int *array = parallel_fill_array(array_size, cpu_num);
    int array_expected[] = {0, 1, 2, 3};

    for (int i = 0; i < array_size; i++) {
        EXPECT_EQ(array_expected[i], array[i]);
    }

    free(array);
}

TEST(TestConsistFillArray, ParallelFillArraySizeIsBigger) {
    int array_size = 5;
    int cpu_num = 4;
    int *array = parallel_fill_array(array_size, cpu_num);
    int array_expected[] = {0, 1, 2, 3, 0};

    for (int i = 0; i < array_size; i++) {
        EXPECT_EQ(array_expected[i], array[i]);
    }

    free(array);
}

TEST(TestConsistFillArray, ParallelFillWithRemeinderOfDivision) {
    int array_size = 10;
    int cpu_num = 3;
    int *array = parallel_fill_array(array_size, cpu_num);
    int array_expected[] = {0, 1, 2, 3, 0, 1, 2, 3, 0, 1};

    for (int i = 0; i < array_size; i++) {
        EXPECT_EQ(array_expected[i], array[i]);
    }

    free(array);
}


