/*
 * bezier_test.cpp
 * 
 * Contains unit tests for bezier.h/cpp
 */


#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "bezier.h"


#define BEZ_TRUE 1
#define BEZ_FALSE 0

#define ERROR_TOLERANCE 0.000001


/*
 * function: is_close
 * 
 * Returns BEZ_TRUE if a and b are within ERROR_TOLERANCE of each other,
 *     BEZ_FALSE otherwise.
 */
int is_close(BEZ_DTYPE a, BEZ_DTYPE b);

/*
 * function: randomUniform
 *
 * Returns a random value uniformly distributed on [a, b].
 */
double randomUniform(double a, double b);

/*
 * function: roundDigits
 *
 * Rounds x to d digits.
 */
double roundDigits(double x, int d);


int main(int argc, char* argv[]) {
    BEZ_DTYPE x,  y,  z,
              x0, y0, z0,
              x1, y1, z1,
              x2, y2, z2,
              x3, y3, z3,
              a,  b,  c,
              a0, b0, c0,
              a1, b1, c1,
              a2, b2, c2,
              a3, b3, c3,
              d,  e,  f,
              d0, e0, f0,
              d1, e1, f1,
              d2, e2, f2,
              d3, e3, f3,
              t,  t2, t3;
    int num_tests = -1, num_fails = -1;
    int i;
    int failed;

    srand(7);

    printf("Beginning unit tests for bezier.h/cpp\n");


    //*************************************************************************
    printf("\nTesting function bezEvaluate2D:\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;

    // test 1
    bezEvaluate2D(8., -8.5,
                  2.5, 3.17,
                  -3.92, -8.5,
                  -5.33, -0.17,
                  0.48,
                  &x, &y);

    if (!(is_close(x, 0.09990656) && is_close(y, -3.03475072))) {
        num_fails++;
        printf("failed test 1\n");
    }

    // test 2
    bezEvaluate2D(1.020, -1.751,
        -9.714, 1.088,
        3.858, 7.276,
        -1.979, -0.229,
        0.921,
        &x, &y);

    if (!(is_close(x, -0.937473) && is_close(y, 1.301713))) {
        num_fails++;
        printf("failed test 2\n");
    }

    // test 3
    bezEvaluate2D(7.375, -2.219,
        -3.535, 8.732,
        -7.919, 4.900,
        3.940, -5.590,
        0.972,
        &x, &y);

    if (!(is_close(x, 2.981834) && is_close(y, -4.724678))) {
        num_fails++;
        printf("failed test 3\n");
    }

    // test 4
    bezEvaluate2D(1.570, 0.442,
        -2.730, 0.089,
        -0.759, -3.666,
        4.495, 5.355,
        0.579,
        &x, &y);

    if (!(is_close(x, -0.172195) && is_close(y, -0.452407))) {
        num_fails++;
        printf("failed test 4\n");
    }

    // test 5
    bezEvaluate2D(0.391, 4.742,
        -1.812, 7.428,
        -4.222, -4.061,
        -6.599, -3.384,
        0.495,
        &x, &y);

    if (!(is_close(x, -3.003507) && is_close(y, 1.505853))) {
        num_fails++;
        printf("failed test 5\n");
    }

    if (num_fails == 0) {
        printf("all %d tests passed\n", num_tests);
    }
    else {
        printf("failed %d/%d tests\n", num_fails, num_tests);
    }
    num_tests = num_fails = -1;


    //*************************************************************************
    printf("\nTesting function bezEvaluate3D:\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;

    // test 1
    bezEvaluate3D(-0.085, -3.165, -5.487,
        -2.688, 0.121, -9.054,
        3.462, -4.075, 2.702,
        1.990, -3.235, -9.770,
        0.770,
        &x, &y, &z);

    if (!(is_close(x, 1.995303) && is_close(y, -3.167693) && is_close(z, -4.528087))) {
        num_fails++;
        printf("failed test 1\n");
    }
    
    // test 2
    bezEvaluate3D(-1.627, 1.590, 9.890,
        6.000, -6.634, -4.713,
        -8.020, 6.408, -2.321,
        8.965, -9.773, 9.478,
        0.887,
        &x, &y, &z);

    if (!(is_close(x, 4.318822) && is_close(y, -5.334236) && is_close(z, 5.849442))) {
        num_fails++;
        printf("failed test 2\n");
    }

    // test 3
    bezEvaluate3D(6.125, 3.297, 0.050,
        -4.688, 3.332, 5.583,
        -3.735, -9.641, -2.259,
        -5.602, -1.328, -5.653,
        0.372,
        &x, &y, &z);

    if (!(is_close(x, -1.808500) && is_close(y, -0.298822) && is_close(z, 1.589678))) {
        num_fails++;
        printf("failed test 3\n");
    }

    // test 4
    bezEvaluate3D(3.779, 1.244, 5.237,
        -1.377, -5.720, 7.340,
        0.612, -3.158, 3.000,
        -1.787, -6.210, 3.324,
        0.069,
        &x, &y, &z);

    if (!(is_close(x, 2.809971) && is_close(y, -0.066462) && is_close(z, 5.583944))) {
        num_fails++;
        printf("failed test 4\n");
    }

    // test 5
    bezEvaluate3D(-7.163, 2.407, 0.817,
        6.783, -8.709, -6.997,
        -9.094, 8.926, 0.450,
        1.499, -0.647, -7.767,
        0.029,
        &x, &y, &z);

    if (!(is_close(x, -6.023568) && is_close(y, 1.511082) && is_close(z, 0.174931))) {
        num_fails++;
        printf("failed test 5\n");
    }

    if (num_fails == 0) {
        printf("all %d tests passed\n", num_tests);
    }
    else {
        printf("failed %d/%d tests\n", num_fails, num_tests);
    }
    num_tests = num_fails = -1;


    //*************************************************************************
    printf("\nTesting function bezSplitCurve2D:\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;
    failed = BEZ_FALSE;

    for (i = 0; i < num_tests; i++) {
        x0 = randomUniform(-10., 10.);
        y0 = randomUniform(-10., 10.);
        x1 = randomUniform(-10., 10.);
        y1 = randomUniform(-10., 10.);
        x2 = randomUniform(-10., 10.);
        y2 = randomUniform(-10., 10.);
        x3 = randomUniform(-10., 10.);
        y3 = randomUniform(-10., 10.);
        t = randomUniform(0., 1.);

        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t, &x, &y);

        bezSplitCurve2D(x0, y0,
                        x1, y1,
                        x2, y2,
                        x3, y3,
                        t,
                        &a0, &b0,
                        &a1, &b1,
                        &a2, &b2,
                        &a3, &b3,
                        &d0, &e0,
                        &d1, &e1,
                        &d2, &e2,
                        &d3, &e3);

        if (!(is_close(a0, x0) && is_close(b0, y0))) {
            failed = BEZ_TRUE;
            printf("failed test: beginning of sub-curve 1 does not match original curve at t=0\n");
        }

        if (!(is_close(a3, x) && is_close(b3, y))) {
            failed = BEZ_TRUE;
            printf("failed test: end of sub-curve 1 does not match original curve at t\n");
        }

        if (!(is_close(d0, x) && is_close(e0, y))) {
            failed = BEZ_TRUE;
            printf("failed test: beginning of sub-curve 2 does not match original curve at t\n");
        }

        if (!(is_close(d3, x3) && is_close(e3, y3))) {
            failed = BEZ_TRUE;
            printf("failed test: end of sub-curve 2 does not match original curve at t=1\n");
        }

        t2 = randomUniform(0., t);
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t2, &x, &y);
        bezEvaluate2D(a0, b0, a1, b1, a2, b2, a3, b3, t2 / t, &a, &b);
        if (!(is_close(x, a) && is_close(y, b))) {
            failed = BEZ_TRUE;
            printf("failed test: sub-curve 1 and original curve do not match at random t\n");
        }

        t2 = randomUniform(t, 1.);
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t2, &x, &y);
        bezEvaluate2D(d0, e0, d1, e1, d2, e2, d3, e3, (t2 - t) / (1. - t), &d, &e);
        if (!(is_close(x, d) && is_close(y, e))) {
            failed = BEZ_TRUE;
            printf("failed test: sub-curve 2 and original curve do not match at random t\n");
        }

        if (failed) {
            num_fails++;
        }
    }

    if (num_fails == 0) {
        printf("all %d tests passed\n", num_tests);
    }
    else {
        printf("failed %d/%d tests\n", num_fails, num_tests);
    }
    num_tests = num_fails = -1;


    //*************************************************************************
    printf("\nTesting function bezSplitCurve3D:\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;
    failed = BEZ_FALSE;

    for (i = 0; i < num_tests; i++) {
        x0 = randomUniform(-10., 10.);
        y0 = randomUniform(-10., 10.);
        z0 = randomUniform(-10., 10.);
        x1 = randomUniform(-10., 10.);
        y1 = randomUniform(-10., 10.);
        z1 = randomUniform(-10., 10.);
        x2 = randomUniform(-10., 10.);
        y2 = randomUniform(-10., 10.);
        z2 = randomUniform(-10., 10.);
        x3 = randomUniform(-10., 10.);
        y3 = randomUniform(-10., 10.);
        z3 = randomUniform(-10., 10.);
        t = randomUniform(0., 1.);

        bezEvaluate3D(x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3, t, &x, &y, &z);

        bezSplitCurve3D(x0, y0, z0,
                        x1, y1, z1,
                        x2, y2, z2,
                        x3, y3, z3,
                        t,
                        &a0, &b0, &c0,
                        &a1, &b1, &c1,
                        &a2, &b2, &c2,
                        &a3, &b3, &c3,
                        &d0, &e0, &f0,
                        &d1, &e1, &f1,
                        &d2, &e2, &f2,
                        &d3, &e3, &f3);

        if (!(is_close(a0, x0) && is_close(b0, y0) && is_close(c0, z0))) {
            failed = BEZ_TRUE;
            printf("failed test: beginning of sub-curve 1 does not match original curve at t=0\n");
        }

        if (!(is_close(a3, x) && is_close(b3, y) && is_close(c3, z))) {
            failed = BEZ_TRUE;
            printf("failed test: end of sub-curve 1 does not match original curve at t\n");
        }

        if (!(is_close(d0, x) && is_close(e0, y) && is_close(f0, z))) {
            failed = BEZ_TRUE;
            printf("failed test: beginning of sub-curve 2 does not match original curve at t\n");
        }

        if (!(is_close(d3, x3) && is_close(e3, y3) && is_close(f3, z3))) {
            failed = BEZ_TRUE;
            printf("failed test: end of sub-curve 2 does not match original curve at t=1\n");
        }

        t2 = randomUniform(0., t);
        bezEvaluate3D(x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3, t2, &x, &y, &z);
        bezEvaluate3D(a0, b0, c0, a1, b1, c1, a2, b2, c2, a3, b3, c3, t2 / t, &a, &b, &c);
        if (!(is_close(x, a) && is_close(y, b) && is_close(z, c))) {
            failed = BEZ_TRUE;
            printf("failed test: sub-curve 1 and original curve do not match at random t\n");
        }

        t2 = randomUniform(t, 1.);
        bezEvaluate3D(x0, y0, z0, x1, y1, z1, x2, y2, z2, x3, y3, z3, t2, &x, &y, &z);
        bezEvaluate3D(d0, e0, f0, d1, e1, f1, d2, e2, f2, d3, e3, f3, (t2 - t) / (1. - t), &d, &e, &f);
        if (!(is_close(x, d) && is_close(y, e) && is_close(z, f))) {
            failed = BEZ_TRUE;
            printf("failed test: sub-curve 2 and original curve do not match at random t\n");
        }

        if (failed) {
            num_fails++;
        }
    }

    if (num_fails == 0) {
        printf("all %d tests passed\n", num_tests);
    }
    else {
        printf("failed %d/%d tests\n", num_fails, num_tests);
    }
    num_tests = num_fails = -1;


    return 0;
}


/*
 * function: is_close
 * 
 * Returns BEZ_TRUE if a and b are within ERROR_TOLERANCE of each other,
 *     BEZ_FALSE otherwise.
 */
int is_close(BEZ_DTYPE a, BEZ_DTYPE b) {
    BEZ_DTYPE diff = a - b;
    
    if (diff < 0) {
        diff = -diff;
    }

    if (diff <= ERROR_TOLERANCE) {
        return BEZ_TRUE;
    }
    else {
        return BEZ_FALSE;
    }
}

/*
 * function: randomUniform
 *
 * Returns a random value uniformly distributed on [a, b].
 */
double randomUniform(double a, double b) {
    double r = (double)(rand()) / (double)RAND_MAX;  // distributed on [0, 1]
    return r * (b - a) + a;
}

/*
 * function: roundDigits
 *
 * Rounds x to d digits.
 */
double roundDigits(double x, int d) {
    double mult = pow(10, (double)(d));
    return round(x * mult) / mult;
}
