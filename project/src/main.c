#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "config.h"
#include "prog.h"

#define CONVERT_TO_SEC 1000000000.0
#define FILENAME "env"

int main() {
    size_t array_size = parse_config_file(FILENAME);

    struct timespec start, finish;

    clock_gettime(CLOCK_MONOTONIC, &start);

    int *array = run_program(array_size);

    clock_gettime(CLOCK_MONOTONIC, &finish);

    double elapsed = (double)(finish.tv_sec - start.tv_sec);
    elapsed += (double)(finish.tv_nsec - start.tv_nsec) / CONVERT_TO_SEC;

    printf("%lf\n", elapsed);

    free(array);

    return 0;
}
