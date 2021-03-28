#include <gtest/gtest.h>

extern "C" {
#include "consistent.h"
}

TEST(TestConsistFillArray, ConsistantFill) {
    int array_size = 5;
    int *array = consistent_fill_array(array_size);
    int array_expected[] = {0, 1, 2, 3, 0};

    for (int i = 0; i < array_size; i++) {
        EXPECT_EQ(array_expected[i], array[i]);
    }

    free(array);
}
