#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "config.h"


config_t* parse_config_file(char *filename) {
    FILE *file_config = fopen(filename, "r");
    if (!file_config) {
        perror("failed to open env file");
        return NULL;
    }

    char mode[20];

    config_t *config = calloc(1, sizeof(config_t));
    if (!config) {
        printf("failed to allocate memory");
        return NULL;
    }

    if (fscanf(file_config, "%19s", mode) != 1) {
        perror("failed to read mode from config");
        return NULL;
    }

    if (strcmp(mode, "parallel") == 0) {
        config->mode = 1;
    } else { // consistent by default
        config->mode = 0;
    }

    if (fscanf(file_config, "%d", &config->array_size) != 1) {
        perror("failed to read array size from config");
        return NULL;
    }

    if (fscanf(file_config, "%d", &config->cpu_number) != 1) {
        perror("failed to read cpu_number from config");
        return NULL;
    }

    fclose(file_config);

    return config;
}
