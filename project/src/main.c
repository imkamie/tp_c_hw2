#include <time.h>
#include <stdio.h>

#include "consistent.h"
#include "parallel.h"

int main() {
    int t = clock();
    consistent_fill_array();


    float sec = ((float)t) / CLOCKS_PER_SEC;

    printf("%f\n", sec);


    int number_of_cpu = 0;
    scanf("%d", &number_of_cpu);


    struct timespec start, finish;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);

    parallel_fill_array(number_of_cpu);

    clock_gettime(CLOCK_MONOTONIC, &finish);

    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("parallel: %lf\n", elapsed);


    return 0;
}
