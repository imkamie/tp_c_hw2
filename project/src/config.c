#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "config.h"

size_t parse_config_file(const char *filename) {
    size_t array_size = 0;

    FILE* file_config = fopen(filename, "r");
    if (!file_config) {
        return ENOENT;
    }

    if (fscanf(file_config, "%zu", &array_size) != 1) {
        fclose(file_config);
        return EINVAL;
    }

    fclose(file_config);

    return array_size;
}
