/*
 * bezier_test.cpp
 * 
 * Contains unit tests for bezier.h/cpp
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "bezier.h"


void benchmarkFunc(void);



int main(int argc, char* argv[]) {
    time_t start_time, end_time;
    clock_t start_clock, end_clock;
    struct timespec start_timespec, end_timespec;

    double x;

    time(&start_time);
    start_clock = clock();
    timespec_get(&start_timespec, TIME_UTC);

    benchmarkFunc();

    time(&end_time);
    end_clock = clock();
    timespec_get(&end_timespec, TIME_UTC);

    printf("Time elapsed according to...\n");

    printf("time()\t\t%.8f\n", (double)(end_time - start_time));

    printf("clock()\t\t%.8f\n", (double)((double)end_clock - (double)start_clock) / (double)(CLOCKS_PER_SEC));

    printf("timespec_get()\t%.8f\n", (double)(end_timespec.tv_sec - start_timespec.tv_sec) + (double)(end_timespec.tv_nsec - start_timespec.tv_nsec) * 1e-9);

    return 0;
}


void benchmarkFunc(void) {
    long double x;
    int i;

    for (i = 0; i < 100000000; i++) {
        x = sqrtl(1.23456789);
    }
}
