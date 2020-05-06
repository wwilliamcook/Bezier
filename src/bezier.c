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
 * function: bez2Evaluate
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
void bez2Evaluate(BEZ_DTYPE x0, BEZ_DTYPE y0,
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
 * function: bez2EvaluateQuadratic
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
void bez2EvaluateQuadratic(BEZ_DTYPE x0, BEZ_DTYPE y0,
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
 * function: bez2EvaluateLinear
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
void bez2EvaluateLinear(BEZ_DTYPE x0, BEZ_DTYPE y0,
                        BEZ_DTYPE x1, BEZ_DTYPE y1,
                        BEZ_DTYPE t,
                        BEZ_DTYPE *x_out, BEZ_DTYPE *y_out) {
    BEZ_DTYPE omt = 1. - t;  // one minus t

    *x_out = x0 * omt + x1 * t;
    *y_out = y0 * omt + y1 * t;
}

/*
 * function: bez3Evaluate
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
void bez3Evaluate(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
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
 * function: bez3EvaluateQuadratic
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
void bez3EvaluateQuadratic(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
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
 * function: bez3EvaluateLinear
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
void bez3EvaluateLinear(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
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
 * function: bez2SplitCurve
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
void bez2SplitCurve(BEZ_DTYPE x0, BEZ_DTYPE y0,
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
 * function: bez3SplitCurve
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
void bez3SplitCurve(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
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
 * function: bez2Derivative
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
void bez2Derivative(BEZ_DTYPE x0, BEZ_DTYPE y0,
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
 * function: bez2DerivativeQuadratic
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
void bez2DerivativeQuadratic(BEZ_DTYPE x0, BEZ_DTYPE y0,
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
 * function: bez2DerivativeLinear
 * 
 * Calculates the derivative of a linear Bezier curve.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second anchor point
 *   x0_out, y0_out: references for the derivative
 */
void bez2DerivativeLinear(BEZ_DTYPE x0, BEZ_DTYPE y0,
                          BEZ_DTYPE x1, BEZ_DTYPE y1,
                          BEZ_DTYPE *x0_out, BEZ_DTYPE *y0_out) {
    *x0_out = x1 - x0;
    *y0_out = y1 - y0;
}


//*****************************************************************************
//* BOUNDING BOX
//*****************************************************************************

/*
 * function: bez2BoundingBox
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
void bez2BoundingBox(BEZ_DTYPE x0, BEZ_DTYPE y0,
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
    a = -x0 + 3. * x1 - 3. * x2 + x3;
    b = 2. * (x0 - 2. * x1 + x2);
    c = -x0 + x1;

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
        sqrtdisc = BEZ_SQRT_FUNC(disc);

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
        bez2Evaluate(x0, y0, x1, y1, x2, y2, x3, y3, t0, &temp1, &temp2);
        if (temp1 < *x_min) {
            *x_min = temp1;
        }
        if (temp1 > *x_max) {
            *x_max = temp1;
        }
        bez2Evaluate(x0, y0, x1, y1, x2, y2, x3, y3, t1, &temp1, &temp2);
        if (temp1 < *x_min) {
            *x_min = temp1;
        }
        if (temp1 > *x_max) {
            *x_max = temp1;
        }
        break;
    case 1:
        bez2Evaluate(x0, y0, x1, y1, x2, y2, x3, y3, t0, &temp1, &temp2);
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
    a = -y0 + 3. * y1 - 3. * y2 + y3;
    b = 2. * (y0 - 2. * y1 + y2);
    c = -y0 + y1;

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
        sqrtdisc = BEZ_SQRT_FUNC(disc);

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
        bez2Evaluate(x0, y0, x1, y1, x2, y2, x3, y3, t0, &temp1, &temp2);
        if (temp2 < *y_min) {
            *y_min = temp2;
        }
        if (temp2 > *y_max) {
            *y_max = temp2;
        }
        bez2Evaluate(x0, y0, x1, y1, x2, y2, x3, y3, t1, &temp1, &temp2);
        if (temp2 < *y_min) {
            *y_min = temp2;
        }
        if (temp2 > *y_max) {
            *y_max = temp2;
        }
        break;
    case 1:
        bez2Evaluate(x0, y0, x1, y1, x2, y2, x3, y3, t0, &temp1, &temp2);
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


//*****************************************************************************
//* FLATNESS
//*****************************************************************************

/*
 * function: bez2IsFlat
 * 
 * Returns BEZ_TRUE if the curve is approximately flat, BEZ_FALSE otherwise.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second control point
 *   x3, y3: coordinates of second anchor point
 *   flatness_threshold: max ratio of hull perimeter to anchor distance for flat
 */
BEZ_DTYPE bez2IsFlat(BEZ_DTYPE x0, BEZ_DTYPE y0,
                     BEZ_DTYPE x1, BEZ_DTYPE y1,
                     BEZ_DTYPE x2, BEZ_DTYPE y2,
                     BEZ_DTYPE x3, BEZ_DTYPE y3,
                     BEZ_DTYPE flatness_threshold) {
    BEZ_DTYPE hull_perimeter;
    BEZ_DTYPE anchor_distance;
    BEZ_DTYPE temp1, temp2;

    temp1 = x0 - x1;
    temp2 = y0 - y1;
    hull_perimeter = BEZ_SQRT_FUNC(temp1 * temp1 + temp2 * temp2);

    temp1 = x1 - x2;
    temp2 = y1 - y2;
    hull_perimeter += BEZ_SQRT_FUNC(temp1 * temp1 + temp2 * temp2);

    temp1 = x2 - x3;
    temp2 = y2 - y3;
    hull_perimeter += BEZ_SQRT_FUNC(temp1 * temp1 + temp2 * temp2);

    temp1 = x0 - x3;
    temp2 = y0 - y3;
    anchor_distance = BEZ_SQRT_FUNC(temp1 * temp1 + temp2 * temp2);

    if (hull_perimeter <= flatness_threshold * anchor_distance) {
        return BEZ_TRUE;
    }
    else {
        return BEZ_FALSE;
    }
}


//*****************************************************************************
//* ARC LENGTH
//*****************************************************************************

/*
 * function: bez2ArcLength
 * 
 * Returns the approximate arc length of the cubic Bezier curve.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second control point
 *   x3, y3: coordinates of second anchor point
 *   flatness_threshold: max ratio of hull perimeter to anchor distance for flat
 */
BEZ_DTYPE bez2ArcLength(BEZ_DTYPE x0, BEZ_DTYPE y0,
                        BEZ_DTYPE x1, BEZ_DTYPE y1,
                        BEZ_DTYPE x2, BEZ_DTYPE y2,
                        BEZ_DTYPE x3, BEZ_DTYPE y3,
                        BEZ_DTYPE flatness_threshold) {
    {
        BEZ_DTYPE hull_perimeter;
        BEZ_DTYPE anchor_distance;
        BEZ_DTYPE temp_x, temp_y;

        temp_x = x0 - x1;
        temp_y = y0 - y1;
        hull_perimeter = BEZ_SQRT_FUNC(temp_x * temp_x + temp_y * temp_y);

        temp_x = x1 - x2;
        temp_y = y1 - y2;
        hull_perimeter += BEZ_SQRT_FUNC(temp_x * temp_x + temp_y * temp_y);

        temp_x = x2 - x3;
        temp_y = y2 - y3;
        hull_perimeter += BEZ_SQRT_FUNC(temp_x * temp_x + temp_y * temp_y);

        temp_x = x0 - x3;
        temp_y = y0 - y3;
        anchor_distance = BEZ_SQRT_FUNC(temp_x * temp_x + temp_y * temp_y);

        if (hull_perimeter <= flatness_threshold * anchor_distance) {
            return (hull_perimeter + anchor_distance) * .5;
        }
    }

    BEZ_DTYPE a0, b0, a1, b1, a2, b2, a3, b3, d0, e0, d1, e1, d2, e2, d3, e3;
    bez2SplitCurve(x0, y0,
                   x1, y1,
                   x2, y2,
                   x3, y3,
                   0.5,
                   &a0, &b0,
                   &a1, &b1,
                   &a2, &b2,
                   &a3, &b3,
                   &d0, &e0,
                   &d1, &e1,
                   &d2, &e2,
                   &d3, &e3);
    return bez2ArcLength(a0, b0, a1, b1, a2, b2, a3, b3, flatness_threshold) +
        bez2ArcLength(d0, e0, d1, e1, d2, e2, d3, e3, flatness_threshold);
}

/*
 * function: bez3ArcLength
 * 
 * Returns the approximate arc length of the cubic Bezier curve.
 * 
 * Args:
 *   x0, y0: coordinates of first anchor point
 *   x1, y1: coordinates of first control point
 *   x2, y2: coordinates of second control point
 *   x3, y3: coordinates of second anchor point
 *   flatness_threshold: max ratio of hull perimeter to anchor distance for flat
 */
BEZ_DTYPE bez3ArcLength(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
                        BEZ_DTYPE x1, BEZ_DTYPE y1, BEZ_DTYPE z1,
                        BEZ_DTYPE x2, BEZ_DTYPE y2, BEZ_DTYPE z2,
                        BEZ_DTYPE x3, BEZ_DTYPE y3, BEZ_DTYPE z3,
                        BEZ_DTYPE flatness_threshold) {
    BEZ_DTYPE hull_perimeter;
    BEZ_DTYPE anchor_distance;
    BEZ_DTYPE temp_x, temp_y, temp_z;

    temp_x = x0 - x1;
    temp_y = y0 - y1;
    temp_z = z0 - z1;
    hull_perimeter = BEZ_SQRT_FUNC(temp_x * temp_x + temp_y * temp_y + temp_z * temp_z);

    temp_x = x1 - x2;
    temp_y = y1 - y2;
    temp_z = z1 - z2;
    hull_perimeter += BEZ_SQRT_FUNC(temp_x * temp_x + temp_y * temp_y + temp_z * temp_z);

    temp_x = x2 - x3;
    temp_y = y2 - y3;
    temp_z = z2 - z3;
    hull_perimeter += BEZ_SQRT_FUNC(temp_x * temp_x + temp_y * temp_y + temp_z * temp_z);

    temp_x = x0 - x3;
    temp_y = y0 - y3;
    temp_z = z0 - z3;
    anchor_distance = BEZ_SQRT_FUNC(temp_x * temp_x + temp_y * temp_y + temp_z * temp_z);

    if (hull_perimeter <= flatness_threshold * anchor_distance) {
        return (hull_perimeter + anchor_distance) * .5;
    }
    else {
        BEZ_DTYPE a0, b0, c0,
                  a1, b1, c1,
                  a2, b2, c2,
                  a3, b3, c3,
                  d0, e0, f0,
                  d1, e1, f1,
                  d2, e2, f2,
                  d3, e3, f3;
        bez3SplitCurve(x0, y0, z0,
                       x1, y1, z1,
                       x2, y2, z2,
                       x3, y3, z3,
                       0.5,
                       &a0, &b0, &c0,
                       &a1, &b1, &c1,
                       &a2, &b2, &c2,
                       &a3, &b3, &c3,
                       &d0, &e0, &f0,
                       &d1, &e1, &f1,
                       &d2, &e2, &f2,
                       &d3, &e3, &f3);
        return bez3ArcLength(a0, b0, c0, a1, b1, c1, a2, b2, c2, a3, b3, c3, flatness_threshold) +
            bez3ArcLength(d0, e0, f0, d1, e1, f1, d2, e2, f2, d3, e3, f3, flatness_threshold);
    }
}
