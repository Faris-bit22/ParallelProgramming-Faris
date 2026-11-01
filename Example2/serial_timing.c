#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void) {
    struct timespec start, end;
    double elapsed_time;

    clock_gettime(CLOCK_MONOTONIC, &start);

    printf("Working for 3 seconds...\n");
    sleep(3);

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed_time = (end.tv_sec - start.tv_sec)
                 + (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    printf("Elapsed time: %.9f seconds\n", elapsed_time);

    return 0;
}