/*
 * bezier_test.cpp
 * 
 * Performs benchmarks on the functions defined in bezier.h and prints them to
 * the screen while logging them to a file.
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>

#include "bezier.h"
#include "benchmark.h"


// constants used to determine how long to time an operation
#define MIN_DURATION 2.
#define MAX_DURATION 5.

// name of file to log the benchmarks to
#define LOG_FILE_NAME "bezier_benchmark.log"


int main(int argc, char* argv[]) {
    FILE* log_file;
    BOOL log = TRUE;
    double ops_per_sec, micros_per_op;
    BEZ_DTYPE x, y, z,
        x0, y0, z0,
        x1, y1, z1,
        x2, y2, z2,
        x3, y3, z3,
        a, b, c,
        a0, b0, c0,
        a1, b1, c1,
        a2, b2, c2,
        a3, b3, c3,
        d, e, f,
        d0, e0, f0,
        d1, e1, f1,
        d2, e2, f2,
        d3, e3, f3,
        t, t2, t3;

    log_file = fopen(LOG_FILE_NAME, "w+");
    if (log_file == NULL) {
        fprintf(stderr, "Error: unable to open log file.\n");
        log = FALSE;
    }

    printAndLog(log_file, log, "Beginning benchmarks for bezier.h\n");


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming function bezEvaluate2D:\n");
    //*************************************************************************

    timeThisCode(ops_per_sec, micros_per_op, MIN_DURATION, MAX_DURATION,
        bezEvaluate2D(8., -8.5,
            2.5, 3.17,
            -3.92, -8.5,
            -5.33, -0.17,
            0.48,
            &x, &y);
    );

    printAndLog(log_file, log, "million operations per second: %f\n", ops_per_sec / 1e6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n", micros_per_op);


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming function bezEvaluate3D:\n");
    //*************************************************************************

    timeThisCode(ops_per_sec, micros_per_op, MIN_DURATION, MAX_DURATION,
        bezEvaluate3D(-0.085, -3.165, -5.487,
            -2.688, 0.121, -9.054,
            3.462, -4.075, 2.702,
            1.990, -3.235, -9.770,
            0.770,
            &x, &y, &z);
    );

    printAndLog(log_file, log, "million operations per second: %f\n", ops_per_sec / 1e6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n", micros_per_op);


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming function bezSplitCurve2D:\n");
    //*************************************************************************

    timeThisCode(ops_per_sec, micros_per_op, MIN_DURATION, MAX_DURATION,
        bezSplitCurve2D(8., -8.5,
            2.5, 3.17,
            -3.92, -8.5,
            -5.33, -0.17,
            0.48,
            &a0, &b0,
            &a1, &b1,
            &a2, &b2,
            &a3, &b3,
            &d0, &e0,
            &d1, &e1,
            &d2, &e2,
            &d3, &e3);
    );

    printAndLog(log_file, log, "million operations per second: %f\n", ops_per_sec / 1e6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n", micros_per_op);


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming function bezSplitCurve3D:\n");
    //*************************************************************************

    timeThisCode(ops_per_sec, micros_per_op, MIN_DURATION, MAX_DURATION,
        bezSplitCurve3D(-0.085, -3.165, -5.487,
            -2.688, 0.121, -9.054,
            3.462, -4.075, 2.702,
            1.990, -3.235, -9.770,
            0.770,
            &a0, &b0, &c0,
            &a1, &b1, &c1,
            &a2, &b2, &c2,
            &a3, &b3, &c3,
            &d0, &e0, &f0,
            &d1, &e1, &f1,
            &d2, &e2, &f2,
            &d3, &e3, &f3);
    );

    printAndLog(log_file, log, "million operations per second: %f\n", ops_per_sec / 1e6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n", micros_per_op);


    printAndLog(log_file, log, "\n\nThis concludes the benchmarks for bezier.h\n");

    fclose(log_file);

    return 0;
}
