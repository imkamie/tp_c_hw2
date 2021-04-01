#include <gtest/gtest.h>
#include <random>

extern "C" {
#include "prog.h"
#include "fill_array.h"
}

TEST(TestConsistFillArray, ConsistantFill) {
    static std::mt19937::result_type rand;
    int array_size = rand;
    int *array = run_program(array_size);
    int* array_expected = (int*) calloc(array_size, sizeof(int));
    if (!array_expected) {
        free(array);
        return;
    }

    array_expected = fill_array(array_expected, 0, array_size);

    for (int i = 0; i < array_size; i++) {
        EXPECT_EQ(array_expected[i], array[i]);
    }

    free(array);
    free(array_expected);
}

TEST(TestConsistFillArray, ZeroArraySize) {
    int array_size = 0;
    int *array = run_program(array_size);

    EXPECT_FALSE(array != nullptr);

    free(array);
}

TEST(TestConsistFillArray, InvalidArraySize) {
    int array_size = -1;
    int *array = run_program(array_size);

    EXPECT_FALSE(array != nullptr);

    free(array);
}

