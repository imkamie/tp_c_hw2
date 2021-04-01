#include <gtest/gtest.h>

extern "C" {
#include "config.h"
}

#define FILENAME "env"

TEST(TestStressForParallelAndConsistent, ReadFromConfig) {
    size_t array_size = parse_config_file(FILENAME);
    size_t zero_array_size = 0;

    EXPECT_NE(zero_array_size, array_size);
    EXPECT_GT(array_size, zero_array_size);
}
