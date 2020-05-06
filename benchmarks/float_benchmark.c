/*
 * float_benchmark.c
 * 
 * Performs benchmarks on floating point arithmetic and prints them to the
 * screen while logging them to a file.
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>

#include "benchmark.h"


// constants used to determine how long to time an operation
#define MIN_DURATION 1e-2
#define MAX_DURATION 2e-2

// name of file to log the benchmarks to
#define LOG_FILE_NAME "float_benchmark.log"


// declare as global variables to prevent optimization
float f = 1.;
double d = 1.;
long double ld = 1.;


int main(int argc, char* argv[]) {
    FILE* log_file;
    BOOL log = TRUE;
    double duration;
    size_t num_executions;

    log_file = fopen(LOG_FILE_NAME, "w+");
    if (log_file == NULL) {
        fprintf(stderr, "Error: unable to open log file.\n");
        log = FALSE;
    }


    printAndLog(log_file, log, "********************************************************************************\n");
    printAndLog(log_file, log, "Beginning benchmarks for data type float.\n");
    printAndLog(log_file, log, "********************************************************************************\n");

    //*************************************************************************
    printAndLog(log_file, log, "\nTiming addition:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        f = f + f;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming subtraction:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        f = f - f;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming multiplication:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        f = f * f;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming division:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        f = f / f;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming square root:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        f = sqrtf(f);
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    printAndLog(log_file, log, "\n\n");
    printAndLog(log_file, log, "********************************************************************************\n");
    printAndLog(log_file, log, "Beginning benchmarks for data type double.\n");
    printAndLog(log_file, log, "********************************************************************************\n");

    //*************************************************************************
    printAndLog(log_file, log, "\nTiming addition (x = y + z):\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        d = d + d;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming subtraction:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        d = d - d;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming multiplication:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        d = d * d;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming division:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        d = d / d;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming square root:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        d = sqrt(d);
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    printAndLog(log_file, log, "\n\n");
    printAndLog(log_file, log, "********************************************************************************\n");
    printAndLog(log_file, log, "Beginning benchmarks for data type long double.\n");
    printAndLog(log_file, log, "********************************************************************************\n");

    //*************************************************************************
    printAndLog(log_file, log, "\nTiming addition:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        ld = ld + ld;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming subtraction:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        ld = ld - ld;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming multiplication:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        ld = ld * ld;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming division:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        ld = ld / ld;
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));


    //*************************************************************************
    printAndLog(log_file, log, "\nTiming square root:\n");

    timeThisCode(MIN_DURATION, MAX_DURATION, duration, num_executions,
        ld = sqrtl(ld);
    );

    printAndLog(log_file, log, "million operations per second: %f\n",
        (double)(num_executions) / duration * 1e-6);
    printAndLog(log_file, log, "microseconds per operation:    %f\n",
        duration * 1e6 / (double)(num_executions));

    printAndLog(log_file, log, "\n\n");
    printAndLog(log_file, log, "********************************************************************************\n");
    printAndLog(log_file, log, "This concludes the floating point operation benchmarks.\n");
    printAndLog(log_file, log, "********************************************************************************\n");

    fclose(log_file);

    return 0;
}
