/*
 * bezier.c
 * 
 * Implementation file for bezier.h.
 */

#include "bezier.h"

#include <math.h>


//*****************************************************************************
//* EVALUATE
//*****************************************************************************

/*
 * function: bezEvaluate2D
 * 
 * Evaluates the position of a cubic Bezier curve at the given t using the
 * definition equation.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second control point
 *   x3, y3: coordinates of second anchor point
 *   t: value of t at which to evaluate the curve
 *   x_out, y_out: references where the output coordinates are stored
 * 
 * Contains 16 floating point multiplications
 */
void bezEvaluate2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                   BEZ_DTYPE x1, BEZ_DTYPE y1,
                   BEZ_DTYPE x2, BEZ_DTYPE y2,
                   BEZ_DTYPE x3, BEZ_DTYPE y3,
                   BEZ_DTYPE t,
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out) {
    BEZ_DTYPE t_squared = t * t;
    BEZ_DTYPE t_cubed = t_squared * t;
    BEZ_DTYPE omt = 1. - t;  // one minus t
    BEZ_DTYPE omt_squared = omt * omt;
    BEZ_DTYPE omt_cubed = omt_squared * omt;
    BEZ_DTYPE coef1 = 3. * t * omt_squared;
    BEZ_DTYPE coef2 = 3. * t_squared * omt;

    *x_out = x0 * omt_cubed + x1 * coef1 + x2 * coef2 + x3 * t_cubed;
    *y_out = y0 * omt_cubed + y1 * coef1 + y2 * coef2 + y3 * t_cubed;
}

/*
 * function: bezEvaluate2D
 * 
 * Evaluates the position of a quadratic Bezier curve at the given t using the
 * definition equation.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of control point
 *   x2, y2: coordinates of second anchor point
 *   t: value of t at which to evaluate the curve
 *   x_out, y_out: references where the output coordinates are stored
 */
void bezEvaluate2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                   BEZ_DTYPE x1, BEZ_DTYPE y1,
                   BEZ_DTYPE x2, BEZ_DTYPE y2,
                   BEZ_DTYPE t,
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out) {
    BEZ_DTYPE t_squared = t * t;
    BEZ_DTYPE omt = 1. - t;  // one minus t
    BEZ_DTYPE omt_squared = omt * omt;
    BEZ_DTYPE coef1 = 2. * t * omt;

    *x_out = x0 * omt_squared + x1 * coef1 + x2 * t_squared;
    *y_out = y0 * omt_squared + y1 * coef1 + y2 * t_squared;
}

/*
 * function: bezEvaluate2D
 * 
 * Evaluates the position of a linear Bezier curve at the given t using the
 * definition equation.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of second anchor point
 *   t: value of t at which to evaluate the curve
 *   x_out, y_out: references where the output coordinates are stored
 */
void bezEvaluate2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                   BEZ_DTYPE x1, BEZ_DTYPE y1,
                   BEZ_DTYPE t,
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out) {
    BEZ_DTYPE omt = 1. - t;  // one minus t

    *x_out = x0 * omt + x1 * t;
    *y_out = y0 * omt + y1 * t;
}

/*
 * function: bezEvaluate3D
 * 
 * Evaluates the position of a cubic Bezier curve at the given t using the
 * definition equation.
 * 
 * Args:
 *   x0, y0, z0: coordinates of first anchor point
 *   x1, y1, z1: coordinates of first control point
 *   x2, y2, z2: coordinates of second control point
 *   x3, y3, z3: coordinates of second anchor point
 *   t: value of t at which to evaluate the curve
 *   x_out, y_out, z_out: references where the output coordinates are stored
 * 
 * Contains 20 floating point multiplications
 */
void bezEvaluate3D(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
                   BEZ_DTYPE x1, BEZ_DTYPE y1, BEZ_DTYPE z1,
                   BEZ_DTYPE x2, BEZ_DTYPE y2, BEZ_DTYPE z2,
                   BEZ_DTYPE x3, BEZ_DTYPE y3, BEZ_DTYPE z3,
                   BEZ_DTYPE t,
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out) {
    BEZ_DTYPE t_squared = t * t;
    BEZ_DTYPE t_cubed = t_squared * t;
    BEZ_DTYPE omt = 1. - t;  // one minus t
    BEZ_DTYPE omt_squared = omt * omt;
    BEZ_DTYPE omt_cubed = omt_squared * omt;
    BEZ_DTYPE coef1 = 3. * t * omt_squared;
    BEZ_DTYPE coef2 = 3. * t_squared * omt;

    *x_out = x0 * omt_cubed + x1 * coef1 + x2 * coef2 + x3 * t_cubed;
    *y_out = y0 * omt_cubed + y1 * coef1 + y2 * coef2 + y3 * t_cubed;
    *z_out = z0 * omt_cubed + z1 * coef1 + z2 * coef2 + z3 * t_cubed;
}

/*
 * function: bezEvaluate3D
 * 
 * Evaluates the position of a quadratic Bezier curve at the given t using the
 * definition equation.
 * 
 * Args:
 *   x0, y0, z0: coordinates of first anchor point
 *   x1, y1, z1: coordinates of control point
 *   x2, y2, z2: coordinates of second anchor point
 *   t: value of t at which to evaluate the curve
 *   x_out, y_out, z_out: references where the output coordinates are stored
 */
void bezEvaluate3D(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
                   BEZ_DTYPE x1, BEZ_DTYPE y1, BEZ_DTYPE z1,
                   BEZ_DTYPE x2, BEZ_DTYPE y2, BEZ_DTYPE z2,
                   BEZ_DTYPE t,
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out) {
    BEZ_DTYPE t_squared = t * t;
    BEZ_DTYPE omt = 1. - t;  // one minus t
    BEZ_DTYPE omt_squared = omt * omt;
    BEZ_DTYPE coef1 = 2. * t * omt;

    *x_out = x0 * omt_squared + x1 * coef1 + x2 * t_squared;
    *y_out = y0 * omt_squared + y1 * coef1 + y2 * t_squared;
    *z_out = z0 * omt_squared + z1 * coef1 + z2 * t_squared;
}

/*
 * function: bezEvaluate3D
 * 
 * Evaluates the position of a linear Bezier curve at the given t using the
 * definition equation.
 * 
 * Args:
 *   x0, y0, z0: coordinates of first anchor point
 *   x1, y1, z1: coordinates of second anchor point
 *   t: value of t at which to evaluate the curve
 *   x_out, y_out, z_out: references where the output coordinates are stored
 */
void bezEvaluate3D(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
                   BEZ_DTYPE x1, BEZ_DTYPE y1, BEZ_DTYPE z1,
                   BEZ_DTYPE t,
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out) {
    BEZ_DTYPE omt = 1. - t;  // one minus t

    *x_out = x0 * omt + x1 * t;
    *y_out = y0 * omt + y1 * t;
    *z_out = z0 * omt + z1 * t;
}


//*****************************************************************************
//* SPLIT
//*****************************************************************************

/*
 * function: bezSplitCurve2D
 * 
 * Splits the Bezier curve into two sub-curves at the given t.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second control point
 *   x3, y3: coordinates of second anchor point
 *   t: value of t at which to split the curve
 *   x0_out0, y0_out0: output for the first anchor point of the first sub-curve
 *   x1_out0, y1_out0: output for the first control point of the first sub-curve
 *   x2_out0, y2_out0: output for the second control point of the first sub-curve
 *   x3_out0, y3_out0: output for the second anchor point of the first sub-curve
 *   x0_out1, y0_out1: output for the first anchor point of the second sub-curve
 *   x1_out1, y1_out1: output for the first control point of the second sub-curve
 *   x2_out1, y2_out1: output for the second control point of the second sub-curve
 *   x3_out1, y3_out1: output for the second anchor point of the second sub-curve
 * 
 * Contains 24 floating point multiplications
 */
void bezSplitCurve2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                     BEZ_DTYPE x1, BEZ_DTYPE y1,
                     BEZ_DTYPE x2, BEZ_DTYPE y2,
                     BEZ_DTYPE x3, BEZ_DTYPE y3,
                     BEZ_DTYPE t,
                     BEZ_DTYPE *x0_out0, BEZ_DTYPE *y0_out0,
                     BEZ_DTYPE *x1_out0, BEZ_DTYPE *y1_out0,
                     BEZ_DTYPE *x2_out0, BEZ_DTYPE *y2_out0,
                     BEZ_DTYPE *x3_out0, BEZ_DTYPE *y3_out0,
                     BEZ_DTYPE *x0_out1, BEZ_DTYPE *y0_out1,
                     BEZ_DTYPE *x1_out1, BEZ_DTYPE *y1_out1,
                     BEZ_DTYPE *x2_out1, BEZ_DTYPE *y2_out1,
                     BEZ_DTYPE *x3_out1, BEZ_DTYPE *y3_out1) {
    BEZ_DTYPE omt = 1. - t;

    *x0_out0 = x0;
    *y0_out0 = y0;

    *x3_out1 = x3;
    *y3_out1 = y3;

    // first de Casteljau step
    x0 = omt * x0 + t * x1;
    y0 = omt * y0 + t * y1;

    x1 = omt * x1 + t * x2;
    y1 = omt * y1 + t * y2;

    x2 = omt * x2 + t * x3;
    y2 = omt * y2 + t * y3;

    *x1_out0 = x0;
    *y1_out0 = y0;

    *x2_out1 = x2;
    *y2_out1 = y2;

    // second de Casteljau step
    x0 = omt * x0 + t * x1;
    y0 = omt * y0 + t * y1;

    x1 = omt * x1 + t * x2;
    y1 = omt * y1 + t * y2;

    *x2_out0 = x0;
    *y2_out0 = y0;

    *x1_out1 = x1;
    *y1_out1 = y1;

    // third de Casteljau step
    *x3_out0 = *x0_out1 = omt * x0 + t * x1;
    *y3_out0 = *y0_out1 = omt * y0 + t * y1;
}

/*
 * function: bezSplitCurve3D
 * 
 * Splits the Bezier curve into two sub-curves at the given t.
 * 
 * Args:
 *   x0, y0, z0: coordinates of first anchor point
 *   x1, y1, z1: coordinates of first control point
 *   x2, y2, z2: coordinates of second control point
 *   x3, y3, z3: coordinates of second anchor point
 *   t: value of t at which to split the curve
 *   x0_out0, y0_out0, z0_out0: output for the first anchor point of the first sub-curve
 *   x1_out0, y1_out0, z1_out0: output for the first control point of the first sub-curve
 *   x2_out0, y2_out0, z2_out0: output for the second control point of the first sub-curve
 *   x3_out0, y3_out0, z3_out0: output for the second anchor point of the first sub-curve
 *   x0_out1, y0_out1, z0_out1: output for the first anchor point of the second sub-curve
 *   x1_out1, y1_out1, z1_out1: output for the first control point of the second sub-curve
 *   x2_out1, y2_out1, z2_out1: output for the second control point of the second sub-curve
 *   x3_out1, y3_out1, z3_out1: output for the second anchor point of the second sub-curve
 * 
 * Contains 36 floating point multiplications
 */
void bezSplitCurve3D(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
                     BEZ_DTYPE x1, BEZ_DTYPE y1, BEZ_DTYPE z1,
                     BEZ_DTYPE x2, BEZ_DTYPE y2, BEZ_DTYPE z2,
                     BEZ_DTYPE x3, BEZ_DTYPE y3, BEZ_DTYPE z3,
                     BEZ_DTYPE t,
                     BEZ_DTYPE *x0_out0, BEZ_DTYPE *y0_out0, BEZ_DTYPE *z0_out0,
                     BEZ_DTYPE *x1_out0, BEZ_DTYPE *y1_out0, BEZ_DTYPE *z1_out0,
                     BEZ_DTYPE *x2_out0, BEZ_DTYPE *y2_out0, BEZ_DTYPE *z2_out0,
                     BEZ_DTYPE *x3_out0, BEZ_DTYPE *y3_out0, BEZ_DTYPE *z3_out0,
                     BEZ_DTYPE *x0_out1, BEZ_DTYPE *y0_out1, BEZ_DTYPE *z0_out1,
                     BEZ_DTYPE *x1_out1, BEZ_DTYPE *y1_out1, BEZ_DTYPE *z1_out1,
                     BEZ_DTYPE *x2_out1, BEZ_DTYPE *y2_out1, BEZ_DTYPE *z2_out1,
                     BEZ_DTYPE *x3_out1, BEZ_DTYPE *y3_out1, BEZ_DTYPE *z3_out1) {
    BEZ_DTYPE omt = 1. - t;

    *x0_out0 = x0;
    *y0_out0 = y0;
    *z0_out0 = z0;

    *x3_out1 = x3;
    *y3_out1 = y3;
    *z3_out1 = z3;

    // first de Casteljau step
    x0 = omt * x0 + t * x1;
    y0 = omt * y0 + t * y1;
    z0 = omt * z0 + t * z1;

    x1 = omt * x1 + t * x2;
    y1 = omt * y1 + t * y2;
    z1 = omt * z1 + t * z2;

    x2 = omt * x2 + t * x3;
    y2 = omt * y2 + t * y3;
    z2 = omt * z2 + t * z3;

    *x1_out0 = x0;
    *y1_out0 = y0;
    *z1_out0 = z0;

    *x2_out1 = x2;
    *y2_out1 = y2;
    *z2_out1 = z2;

    // second de Casteljau step
    x0 = omt * x0 + t * x1;
    y0 = omt * y0 + t * y1;
    z0 = omt * z0 + t * z1;

    x1 = omt * x1 + t * x2;
    y1 = omt * y1 + t * y2;
    z1 = omt * z1 + t * z2;

    *x2_out0 = x0;
    *y2_out0 = y0;
    *z2_out0 = z0;

    *x1_out1 = x1;
    *y1_out1 = y1;
    *z1_out1 = z1;

    // third de Casteljau step
    *x3_out0 = *x0_out1 = omt * x0 + t * x1;
    *y3_out0 = *y0_out1 = omt * y0 + t * y1;
    *z3_out0 = *z0_out1 = omt * z0 + t * z1;
}


//*****************************************************************************
//* DERIVATIVE
//*****************************************************************************

/*
 * function: bezDerivative2D
 * 
 * Calculates the derivative of a cubic Bezier curve and returns the result as
 * the points of a quadratic Bezier curve.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second control point
 *   x3, y3: coordinates of second anchor point
 *   x0_out, y0_out: references for the first anchor point of the derivative
 *   x1_out, y1_out: references for the control point of the derivative
 *   x2_out, y2_out: references for the second anchor point of the derivative
 */
void bezDerivative2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                     BEZ_DTYPE x1, BEZ_DTYPE y1,
                     BEZ_DTYPE x2, BEZ_DTYPE y2,
                     BEZ_DTYPE x3, BEZ_DTYPE y3,
                     BEZ_DTYPE *x0_out, BEZ_DTYPE *y0_out,
                     BEZ_DTYPE *x1_out, BEZ_DTYPE *y1_out,
                     BEZ_DTYPE *x2_out, BEZ_DTYPE *y2_out) {
    *x0_out = 3. * (x1 - x0);
    *y0_out = 3. * (y1 - y0);

    *x1_out = 3. * (x2 - x1);
    *y1_out = 3. * (y2 - y1);

    *x2_out = 3. * (x3 - x2);
    *y2_out = 3. * (y3 - y2);
}

/*
 * function: bezDerivative2D
 * 
 * Calculates the derivative of a quadratic Bezier curve and returns the result
 * as the points of a linear Bezier curve.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second anchor point
 *   x0_out, y0_out: references for the first anchor point of the derivative
 *   x1_out, y1_out: references for the second anchor point of the derivative
 */
void bezDerivative2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                     BEZ_DTYPE x1, BEZ_DTYPE y1,
                     BEZ_DTYPE x2, BEZ_DTYPE y2,
                     BEZ_DTYPE *x0_out, BEZ_DTYPE *y0_out,
                     BEZ_DTYPE *x1_out, BEZ_DTYPE *y1_out) {
    *x0_out = 2. * (x1 - x0);
    *y0_out = 2. * (y1 - y0);

    *x1_out = 2. * (x2 - x1);
    *y1_out = 2. * (y2 - y1);
}

/*
 * function: bezDerivative2D
 * 
 * Calculates the derivative of a linear Bezier curve.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second anchor point
 *   x0_out, y0_out: references for the derivative
 */
void bezDerivative2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                     BEZ_DTYPE x1, BEZ_DTYPE y1,
                     BEZ_DTYPE *x0_out, BEZ_DTYPE *y0_out) {
    *x0_out = x1 - x0;
    *y0_out = y1 - y0;
}


//*****************************************************************************
//* BOUNDING BOX
//*****************************************************************************

/*
 * function: bezBoundingBox2D
 *
 * Computes the coordinates of an axis-aligned bounding box.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second control point
 *   x3, y3: coordinates of second anchor point
 *   x_min, y_min: references to the lower left corner of the box (output)
 *   x_max, y_max: references to the upper right corner of the box (output)
 */
void bezBoundingBox2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                      BEZ_DTYPE x1, BEZ_DTYPE y1,
                      BEZ_DTYPE x2, BEZ_DTYPE y2,
                      BEZ_DTYPE x3, BEZ_DTYPE y3,
                      BEZ_DTYPE* x_min, BEZ_DTYPE* y_min,
                      BEZ_DTYPE* x_max, BEZ_DTYPE* y_max) {
    BEZ_DTYPE a, b, c;
    BEZ_DTYPE t0, t1;  // t values at which the derivative is zero
    BEZ_DTYPE disc, sqrtdisc;  // discriminant in quadratic formula
    BEZ_DTYPE temp1, temp2;
    int num_t;

    // CALCULATE MIN/MAX FOR X
    a = 3. * (-x0 + 3. * x1 - 3. * x2 + x3);
    b = 6. * (x0 - 2. * x1 + x2);
    c = 3. * (-x0 + x1);

    if (x0 < x3) {
        *x_min = x0;
        *x_max = x3;
    }
    else {
        *x_min = x3;
        *x_max = x0;
    }

    disc = b * b - 4. * a * c;

    if (disc > 0.) {
#if BEZ_DTYPE_FLOAT
        sqrtdisc = sqrtf(disc);
#else
        sqrtdisc = sqrt(disc);
#endif

        temp1 = 1. / (2. * a);
        temp2 = -b;

        t0 = (temp2 - sqrtdisc) * temp1;
        t1 = (temp2 + sqrtdisc) * temp1;

        if (t0 < 0. || t0 > 1.) {
            if (t1 < 0. || t1 > 1.) {
                num_t = 0;
            }
            else {
                t0 = t1;
                num_t = 1;
            }
        }
        else if (t1 < 0. || t1 > 1.) {
            num_t = 1;
        }
        else {
            num_t = 2;
        }
    }
    else if (disc == 0.) {
        t0 = -b / (2. * a);

        if (t0 < 0. || t0 > 1.) {
            num_t = 0;
        }
        else {
            num_t = 1;
        }
    }
    else {
        num_t = 0;
    }

    switch (num_t) {
    case 2:
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t0, &temp1, &temp2);
        if (temp1 < *x_min) {
            *x_min = temp1;
        }
        if (temp1 > *x_max) {
            *x_max = temp1;
        }
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t1, &temp1, &temp2);
        if (temp1 < *x_min) {
            *x_min = temp1;
        }
        if (temp1 > *x_max) {
            *x_max = temp1;
        }
        break;
    case 1:
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t0, &temp1, &temp2);
        if (temp1 < *x_min) {
            *x_min = temp1;
        }
        if (temp1 > *x_max) {
            *x_max = temp1;
        }
        break;
    case 0:
        break;
    }

    // CALCULATE MIN/MAX FOR Y
    a = 3. * (-y0 + 3. * y1 - 3. * y2 + y3);
    b = 6. * (y0 - 2. * y1 + y2);
    c = 3. * (-y0 + y1);

    if (y0 < y3) {
        *y_min = y0;
        *y_max = y3;
    }
    else {
        *y_min = y3;
        *y_max = y0;
    }

    disc = b * b - 4. * a * c;

    if (disc > 0.) {
#if BEZ_DTYPE_FLOAT
        sqrtdisc = sqrtf(disc);
#else
        sqrtdisc = sqrt(disc);
#endif

        temp1 = 1. / (2. * a);
        temp2 = -b;

        t0 = (temp2 - sqrtdisc) * temp1;
        t1 = (temp2 + sqrtdisc) * temp1;

        if (t0 < 0. || t0 > 1.) {
            if (t1 < 0. || t1 > 1.) {
                num_t = 0;
            }
            else {
                t0 = t1;
                num_t = 1;
            }
        }
        else if (t1 < 0. || t1 > 1.) {
            num_t = 1;
        }
        else {
            num_t = 2;
        }
    }
    else if (disc == 0.) {
        t0 = -b / (2. * a);

        if (t0 < 0. || t0 > 1.) {
            num_t = 0;
        }
        else {
            num_t = 1;
        }
    }
    else {
        num_t = 0;
    }

    switch (num_t) {
    case 2:
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t0, &temp1, &temp2);
        if (temp2 < *y_min) {
            *y_min = temp2;
        }
        if (temp2 > *y_max) {
            *y_max = temp2;
        }
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t1, &temp1, &temp2);
        if (temp2 < *y_min) {
            *y_min = temp2;
        }
        if (temp2 > *y_max) {
            *y_max = temp2;
        }
        break;
    case 1:
        bezEvaluate2D(x0, y0, x1, y1, x2, y2, x3, y3, t0, &temp1, &temp2);
        if (temp2 < *y_min) {
            *y_min = temp2;
        }
        if (temp2 > *y_max) {
            *y_max = temp2;
        }
        break;
    case 0:
        break;
    }
}
