#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "consistent.h"
#include "parallel.h"

#define CONVERT_TO_SEC 1000000000.0
#define CONSISTENT 0
#define PARALLEL 1

int main() {
    config_t* config = parse_config_file("env");

    if (config->mode == CONSISTENT) {
        int t = clock();
        int *array = consistent_fill_array(config->array_size);

        float sec = ((float)t) / CLOCKS_PER_SEC;

        printf("consistent %f\n", sec);
        free(array);
    } else if (config->mode == PARALLEL) {
        struct timespec start, finish;

        clock_gettime(CLOCK_MONOTONIC, &start);

        int *array = parallel_fill_array(config->array_size, config->cpu_number);

        clock_gettime(CLOCK_MONOTONIC, &finish);

        double elapsed = (double)(finish.tv_sec - start.tv_sec);
        elapsed += (double)(finish.tv_nsec - start.tv_nsec) / CONVERT_TO_SEC;

        printf("parallel: %lf\n", elapsed);

        free(array);
    }

    free(config);
    return 0;
}
