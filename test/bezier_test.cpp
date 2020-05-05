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

#define ERROR_TOLERANCE 1e-6
#define DERIVATIVE_DELTA 1e-4
#define DERIVATIVE_ERROR_TOLERANCE 1e-1


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
    printf("\nTesting function bezEvaluate2D (CUBIC):\n");
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
    printf("\nTesting function bezEvaluate2D (QUADRATIC):\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;

    // test 1
    bezEvaluate2D(5.1, 7.71,
                  -6.86, 9.54,
                  -4.66, 2.78,
                  0.414,
                  &x, &y);

    if (!(is_close(x, -2.37591264) && is_close(y, 7.75294836))) {
        num_fails++;
        printf("failed test 1\n");
    }

    // test 2
    bezEvaluate2D(-0.35, -9.5,
                  -8.57, -0.2,
                  6.44, 3.05,
                  0.754,
                  &x, &y);

    if (!(is_close(x, 0.46086668) && is_close(y, 1.0848782))) {
        num_fails++;
        printf("failed test 2\n");
    }

    // test 3
    bezEvaluate2D(-9.53, 4.27,
                  -4.94, -4.74,
                  -7.7, 0.72,
                  0.031,
                  &x, &y);

    if (!(is_close(x, -9.25248335) && is_close(y, 3.72528567))) {
        num_fails++;
        printf("failed test 3\n");
    }

    // test 4
    bezEvaluate2D(7.43, -3.23,
                  -9.3, -5.33,
                  -6.03, 5.09,
                  0.67,
                  &x, &y);

    if (!(is_close(x, -6.0102) && is_close(y, -0.423772))) {
        num_fails++;
        printf("failed test 4\n");
    }

    // test 5
    bezEvaluate2D(9.04, -4.85,
                  0.28, -7.67,
                  9.67, -5.61,
                  0.88,
                  &x, &y);

    if (!(is_close(x, 7.67776) && is_close(y, -6.034128))) {
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
    printf("\nTesting function bezEvaluate2D (LINEAR):\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;

    // test 1
    bezEvaluate2D(9.25, -6.77,
                  6.76, -4.55,
                  0.811,
                  &x, &y);

    if (!(is_close(x, 7.23061) && is_close(y, -4.96958))) {
        num_fails++;
        printf("failed test 1\n");
    }

    // test 2
    bezEvaluate2D(7.88, -8.43,
                  -3.65, -5.7,
                  0.712,
                  &x, &y);

    if (!(is_close(x, -0.32936) && is_close(y, -6.48624))) {
        num_fails++;
        printf("failed test 2\n");
    }

    // test 3
    bezEvaluate2D(-9.94, 4.22,
                  7.56, -3.18,
                  0.13,
                  &x, &y);

    if (!(is_close(x, -7.665) && is_close(y, 3.258))) {
        num_fails++;
        printf("failed test 3\n");
    }

    // test 4
    bezEvaluate2D(0.35, 9.93,
                  -4.06, -1.58,
                  0.419,
                  &x, &y);

    if (!(is_close(x, -1.49779) && is_close(y, 5.10731))) {
        num_fails++;
        printf("failed test 4\n");
    }

    // test 5
    bezEvaluate2D(-9.29, 0.82,
                  -8.14, -6.9,
                  0.188,
                  &x, &y);

    if (!(is_close(x, -9.0738) && is_close(y, -0.63136))) {
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
    printf("\nTesting function bezEvaluate3D (CUBIC):\n");
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
    printf("\nTesting function bezEvaluate3D (QUADRATIC):\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;

    // test 1
    bezEvaluate3D(6.8, -5.2, -2.,
                  9.92, -3.7, 6.2,
                  -8.6, -1.5, 5.2,
                  0.455,
                  &x, &y, &z);

    if (!(is_close(x, 5.159179) && is_close(y, -3.6900825) && is_close(z, 3.55737))) {
        num_fails++;
        printf("failed test 1\n");
    }
    
    // test 2
    bezEvaluate3D(-6.92, -6.05, 8.64,
                  -1.38, -7.55, -9.52,
                  -5.5, 8.64, 8.4,
                  0.696,
                  &x, &y, &z);

    if (!(is_close(x, -3.88777856) && is_close(y, 0.43131904) && is_close(z, 0.83900928))) {
        num_fails++;
        printf("failed test 2\n");
    }

    // test 3
    bezEvaluate3D(9.55, 1.18, -6.33,
                  4.57, -8.32, -7.9,
                  9.5, 3.01, 1.53,
                  0.906,
                  &x, &y, &z);

    if (!(is_close(x, 8.6607246) && is_close(y, 1.06401388) && is_close(z, -0.145644))) {
        num_fails++;
        printf("failed test 3\n");
    }

    // test 4
    bezEvaluate3D(0.35, 7.13, -6.34,
                  0.32, 3.52, 5.9,
                  0.8, 8.8, 3.,
                  0.634,
                  &x, &y, &z);

    if (!(is_close(x, 0.51695756) && is_close(y, 6.12590884) && is_close(z, 3.09470616))) {
        num_fails++;
        printf("failed test 4\n");
    }

    // test 5
    bezEvaluate3D(1.1, 8.13, 7.5,
                  7.61, 6.82, -8.63,
                  5.4, -2.06, 7.73,
                  0.927,
                  &x, &y, &z);

    if (!(is_close(x, 5.67619112) && is_close(y, -0.80386053) && is_close(z, 5.51457921))) {
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
    printf("\nTesting function bezEvaluate3D (LINEAR):\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;

    // test 1
    bezEvaluate3D(-6.77, 3.2, 8.3,
                  -8.43, 7.65, 4.08,
                  0.88,
                  &x, &y, &z);

    if (!(is_close(x, -8.2308) && is_close(y, 7.116) && is_close(z, 4.5864))) {
        num_fails++;
        printf("failed test 1\n");
    }
    
    // test 2
    bezEvaluate3D(7.74, 4.94, -7.86,
                  -6.59, -4.86, 0.98,
                  0.508,
                  &x, &y, &z);

    if (!(is_close(x, 0.46036) && is_close(y, -0.0384) && is_close(z, -3.36928))) {
        num_fails++;
        printf("failed test 2\n");
    }

    // test 3
    bezEvaluate3D(5.51, -6.14, -5.42,
                  -1.81, 6.1, -5.44,
                  0.283,
                  &x, &y, &z);

    if (!(is_close(x, 3.43844) && is_close(y, -2.67608) && is_close(z, -5.42566))) {
        num_fails++;
        printf("failed test 3\n");
    }

    // test 4
    bezEvaluate3D(9.82, 9.25, -9.31,
                  5.15, -1.5, 3.32,
                  0.215,
                  &x, &y, &z);

    if (!(is_close(x, 8.81595) && is_close(y, 6.93875) && is_close(z, -6.59455))) {
        num_fails++;
        printf("failed test 4\n");
    }

    // test 5
    bezEvaluate3D(-5.63, 5.03, 5.33,
                  -4.22, 9.68, -1.25,
                  0.246,
                  &x, &y, &z);

    if (!(is_close(x, -5.28314) && is_close(y, 6.1739) && is_close(z, 3.71132))) {
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


    //*************************************************************************
    printf("\nTesting function bezDerivative2D (CUBIC):\n");
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

        // compute derivative at t
        bezDerivative2D(x0, y0, x1, y1, x2, y2, x3, y3, &a0, &b0, &a1, &b1, &a2, &b2);
        bezEvaluate2D(a0, b0, a1, b1, a2, b2, t, &a, &b);

        // compute estimate of derivative at t
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t + DERIVATIVE_DELTA, &d0, &e0);
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t - DERIVATIVE_DELTA, &d1, &e1);
        d0 = (d0 - d1) / (2. * DERIVATIVE_DELTA);
        e0 = (e0 - e1) / (2. * DERIVATIVE_DELTA);
        
        if (sqrt(pow(d0 - a, 2.) + pow(e0 - b, 2.)) > DERIVATIVE_ERROR_TOLERANCE) {
            num_fails++;
            printf("failed test %d\n", i + 1);
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
    printf("\nTesting function bezDerivative2D (QUADRATIC):\n");
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
        t = randomUniform(0., 1.);

        // compute derivative at t
        bezDerivative2D(x0, y0, x1, y1, x2, y2, &a0, &b0, &a1, &b1);
        bezEvaluate2D(a0, b0, a1, b1, t, &a, &b);

        // compute estimate of derivative at t
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, t + DERIVATIVE_DELTA, &d0, &e0);
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, t - DERIVATIVE_DELTA, &d1, &e1);
        d0 = (d0 - d1) / (2. * DERIVATIVE_DELTA);
        e0 = (e0 - e1) / (2. * DERIVATIVE_DELTA);
        
        if (sqrt(pow(d0 - a, 2.) + pow(e0 - b, 2.)) > DERIVATIVE_ERROR_TOLERANCE) {
            num_fails++;
            printf("failed test %d\n", i + 1);
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
    printf("\nTesting function bezDerivative2D (LINEAR):\n");
    //*************************************************************************
    num_tests = 5;
    num_fails = 0;
    failed = BEZ_FALSE;

    for (i = 0; i < num_tests; i++) {
        x0 = randomUniform(-10., 10.);
        y0 = randomUniform(-10., 10.);
        x1 = randomUniform(-10., 10.);
        y1 = randomUniform(-10., 10.);
        t = randomUniform(0., 1.);

        bezDerivative2D(x0, y0, x1, y1, &a, &b);

        // compute estimate of derivative at t
        bezEvaluate2D(x0, y0, x1, y1, t + DERIVATIVE_DELTA, &d0, &e0);
        bezEvaluate2D(x0, y0, x1, y1, t - DERIVATIVE_DELTA, &d1, &e1);
        d0 = (d0 - d1) / (2. * DERIVATIVE_DELTA);
        e0 = (e0 - e1) / (2. * DERIVATIVE_DELTA);
        
        if (sqrt(pow(d0 - a, 2.) + pow(e0 - b, 2.)) > DERIVATIVE_ERROR_TOLERANCE) {
            num_fails++;
            printf("failed test %d\n", i + 1);
        }
    }

    if (num_fails == 0) {
        printf("all %d tests passed\n", num_tests);
    }
    else {
        printf("failed %d/%d tests\n", num_fails, num_tests);
    }
    num_tests = num_fails = -1;


    printf("\n\nThis concludes the unit tests for bezier.h/cpp\n");

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
