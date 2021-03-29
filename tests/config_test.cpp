#include <gtest/gtest.h>

extern "C" {
#include "config.h"
}

#define FILENAME "env"

TEST(TestConsistFillArray, ConsistantFill) {
    config_t* config = parse_config_file(FILENAME);
}
