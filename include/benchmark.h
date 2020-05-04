/*
 * benchmark.h
 * 
 * Defines and implements several functions that are helpful for benchmarking.
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <time.h>


#define BOOL int
#define TRUE 1
#define FALSE 0


double timespec2sec(struct timespec start, struct timespec end);
void printAndLog(FILE* log_file, BOOL log, char* format, ...);


/*
 * function-like macro: timeThisCode
 *
 * Executes code_to_time many times and returns the total duration and number
 * of times it was executed.
 *
 * Args:
 *   min_duration: minimum seconds to spend benchmarking the code (double)
 *   max_duration: maximum seconds to spend benchmarking the code (double)
 *   duration: name of variable to store the total duration of execution (double)
 *   num_times: name of variable to store the number of executions (int)
 *   code_to_time: the code whose execution time to measure
 * 
 * NOTE: this function is implemented as a macro to avoid the mess of passing a
 * void (void* arg_data) prototyped function pointer in, which would incur
 * redundant function definitions and obscene argument structs among other
 * nasty things...
 */
#define timeThisCode(min_duration, max_duration, duration, num_times,\
                     code_to_time) {\
    struct timespec start, end;\
    double multiplier;\
    int i;\
    num_times = 1;\
    while (TRUE) {\
        timespec_get(&start, TIME_UTC);\
        for (i = 0; i < num_times; i++) {\
            {code_to_time}\
        }\
        timespec_get(&end, TIME_UTC);\
        duration = timespec2sec(start, end);\
        multiplier = (max_duration) / duration;\
        if (multiplier > 1000.) multiplier = 1000.;\
        if (duration < (min_duration)) num_times *= multiplier;\
        else break;\
    }\
}


/*
 * function: timespec2sec
 * 
 * Returns (end - start) as a float.
 */
double timespec2sec(struct timespec start, struct timespec end) {
    return (double)(end.tv_sec - start.tv_sec) + (double)((double)(end.tv_nsec) - (double)(start.tv_nsec)) * 1e-9;
}

/*
 * function: printAndLog
 * 
 * Prints the given formatted string using printf and additionally logs the
 * result to log_file.
 * 
 * Args:
 *   log_file: file to print the formatted string to
 *   log: whether or not to write the string to the log file
 *   format: the format string
 *   ...: values to be formatted into the string
 */
void printAndLog(FILE* log_file, BOOL log, char* format, ...) {
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if (log) {
        va_start(args, format);
        vfprintf(log_file, format, args);
        va_end(args);
    }
}
