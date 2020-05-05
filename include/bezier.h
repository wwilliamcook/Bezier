/*
 * bezier.h
 * 
 * Defines a set of functions for manipulating individual cubic Bezier curves.
 */

#ifndef BEZIER_BEZIER_H
#define BEZIER_BEZIER_H

#define BEZ_DTYPE float


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
 */
void bezEvaluate2D(BEZ_DTYPE x0, BEZ_DTYPE y0,
                   BEZ_DTYPE x1, BEZ_DTYPE y1,
                   BEZ_DTYPE x2, BEZ_DTYPE y2,
                   BEZ_DTYPE x3, BEZ_DTYPE y3,
                   BEZ_DTYPE t,
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out);

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
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out);

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
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out);

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
 */
void bezEvaluate3D(BEZ_DTYPE x0, BEZ_DTYPE y0, BEZ_DTYPE z0,
                   BEZ_DTYPE x1, BEZ_DTYPE y1, BEZ_DTYPE z1,
                   BEZ_DTYPE x2, BEZ_DTYPE y2, BEZ_DTYPE z2,
                   BEZ_DTYPE x3, BEZ_DTYPE y3, BEZ_DTYPE z3,
                   BEZ_DTYPE t,
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out);

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
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out);

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
                   BEZ_DTYPE *x_out, BEZ_DTYPE *y_out, BEZ_DTYPE *z_out);


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
                     BEZ_DTYPE *x3_out1, BEZ_DTYPE *y3_out1);

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
                     BEZ_DTYPE *x3_out1, BEZ_DTYPE *y3_out1, BEZ_DTYPE *z3_out1);


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
                     BEZ_DTYPE *x2_out, BEZ_DTYPE *y2_out);

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
                     BEZ_DTYPE *x1_out, BEZ_DTYPE *y1_out);

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
                     BEZ_DTYPE *x0_out, BEZ_DTYPE *y0_out);

#endif
