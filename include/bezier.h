/*
 * bezier.h
 * 
 * Defines a set of functions for manipulating individual cubic Bezier curves.
 */

#ifndef BEZIER_BEZIER_H
#define BEZIER_BEZIER_H

// Make booleans more readable
#define BEZ_BOOL int
#define BEZ_TRUE 1
#define BEZ_FALSE 0

// Change these to change the underlying data type of the library
#define BEZ_DTYPE float
#define BEZ_SQRT_FUNC(x) sqrtf(x)

// Allow linkage with C++ code
#ifdef __cplusplus
extern "C" {
#endif


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
 */
void bez2Evaluate(BEZ_DTYPE x0, BEZ_DTYPE y0,
                  BEZ_DTYPE x1, BEZ_DTYPE y1,
                  BEZ_DTYPE x2, BEZ_DTYPE y2,
                  BEZ_DTYPE x3, BEZ_DTYPE y3,
                  BEZ_DTYPE t,
                  BEZ_DTYPE *x_out, BEZ_DTYPE *y_out);

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
                           BEZ_DTYPE *x_out, BEZ_DTYPE *y_out);

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
                        BEZ_DTYPE *x_out, BEZ_DTYPE *y_out);

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
 */
void bez3Evaluate(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
                  BEZ_DTYPE x1, BEZ_DTYPE y1, BEZ_DTYPE z1,
                  BEZ_DTYPE x2, BEZ_DTYPE y2, BEZ_DTYPE z2,
                  BEZ_DTYPE x3, BEZ_DTYPE y3, BEZ_DTYPE z3,
                  BEZ_DTYPE t,
                  BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out);

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
                           BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out);

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
                        BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out);


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
                    BEZ_DTYPE *x3_out1, BEZ_DTYPE *y3_out1);

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
                    BEZ_DTYPE *x3_out1, BEZ_DTYPE *y3_out1, BEZ_DTYPE *z3_out1);


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
                    BEZ_DTYPE *x2_out, BEZ_DTYPE *y2_out);

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
                             BEZ_DTYPE *x1_out, BEZ_DTYPE *y1_out);

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
                          BEZ_DTYPE *x0_out, BEZ_DTYPE *y0_out);


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
                     BEZ_DTYPE* x_max, BEZ_DTYPE* y_max);


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
                     BEZ_DTYPE flatness_threshold);


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
                        BEZ_DTYPE flatness_threshold);

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
                        BEZ_DTYPE flatness_threshold);


// Finish extern "C"
#ifdef __cplusplus
}
#endif

#endif
