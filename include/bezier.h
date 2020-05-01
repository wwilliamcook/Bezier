/*
 * bezier.h
 * 
 * Defines a set of functions for manipulating individual cubic Bezier curves.
 */

#ifndef BEZIER_BEZIER_H
#define BEZIER_BEZIER_H

#define BEZ_DTYPE float


/*
 * function: bezEvaluate2D
 * 
 * Evaluates the position at the given t using the Bezier definition equation.
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
 * function: bezEvaluate3D
 * 
 * Evaluates the position at the given t using the Bezier definition equation.
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

#endif
