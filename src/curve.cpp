/*
 * curve.cpp
 *
 * Implements the class Curve.
 */

#include "curve.h"

#include <stdlib.h>

#include "bezier.h"

#define BEZ_ONE_THIRD 0.33333333333333333333333333333
#define BEZ_TWO_THIRDS 0.66666666666666666666666666666


//*****************************************************************************
// Constructors/Destructors
//*****************************************************************************

/*
 * default constructor
 *
 * Constructs an empty spline.
 */
Curve2D::Curve2D(void) :
    anchor_count(0), bezier_count(0) {
    // Nothing to do
}

/*
 * constructor
 *
 * Constructs a spline from the given anchor points.
 *
 * Args:
 *   anchor_points: ordered anchor points from which to construct spline
 */
Curve2D::Curve2D(const std::vector<bezVect2D>& anchor_points) :
    points(anchor_points) {
    anchor_count = points.size();
    bezier_count = points.size() - 1;

    std::size_t i;
    std::vector<bezVect2D>::iterator iter;
    bezVect2D v{ 0, 0 };

    for (i = 0; i < anchor_count; i++) {
        B_points.push_back(v);
        c.push_back(0.);
    }

    for (i = 1; i < points.size(); ) {
        points.insert(points.begin() + i, v);
        points.insert(points.begin() + i, v);
        i += 3;
    }

    updateControlPoints();
}


//*************************************************************************
// Access functions
//*************************************************************************

/*
 * function: getPositionAt
 *
 * Returns the coordinates of the spline evaluated at the given t.
 *
 * Args:
 *   t: parameter value in the range [0, 1]
 *
 * Throws:
 *   std::out_of_range if 0 <= i <= 1 is not satisfied
 */
bezVect2D Curve2D::getPositionAt(BEZ_DTYPE t) const {
    t *= (BEZ_DTYPE)(bezier_count);
    std::size_t bez_i = (std::size_t)(t);  // index of Bezier curve
    std::size_t k;

    if (bez_i == anchor_count - 1) {
        return points[points.size() - 1];
    }

    bez_i *= 3;  // index of corresponding P_0 in `points`
    t = fmod(t, 1.);
    bezVect2D out;

    bez2Evaluate(points[bez_i][0], points[bez_i][1],
                 points[bez_i + 1][0], points[bez_i + 1][1],
                 points[bez_i + 2][0], points[bez_i + 2][1],
                 points[bez_i + 3][0], points[bez_i + 3][1],
                 t,
                 &out[0], &out[1]);

    return out;
}

/*
 * function: anchorCount
 *
 * Returns the number of anchor points.
 */
std::size_t Curve2D::anchorCount(void) const {
    // Not implemented
    return anchor_count;
}

/*
 * function: getAnchor
 *
 * Returns the coordinates of the anchor point at the given index.
 *
 * Args:
 *   i: index of point
 *
 * Throws:
 *   std::out_of_range if 0 <= i < anchorCount() is not satisfied
 */
const bezVect2D& Curve2D::getAnchor(std::size_t i) const {
    return points[i * 3];
}

/*
 * function: getLength
 *
 * Returns the length of the spline between two parameter values.
 *
 * Args:
 *   t0: value of t to start at
 *   t1: value of t to stop at
 *
 * Throws:
 *   std::out_of_range if 0 <= t0,t1 <= 1 is not satified
 */
BEZ_DTYPE Curve2D::getLength(BEZ_DTYPE t0, BEZ_DTYPE t1) const {
    // Not implemented
    return 0;
}

/*
 * function: getLength
 *
 * Returns the total length of the spline.
 */
BEZ_DTYPE Curve2D::getLength(void) const {
    // Not implemented
    return 0;
}

/*
 * function: split
 *
 * Splits the spline into two sub-splines.
 *
 * Overwrites the two given Curve objects with the sub-splines.
 *
 * Args:
 *   t: parameter value at which to split, in range [0, 1]
 *   c1: sub-spline taken from [0, t]
 *   c2: sub-spline taken from [t, 1]
 *
 * Throws:
 *   std::out_of_range if 0 <= t <= 1 is not satisfied
 */
void Curve2D::split(BEZ_DTYPE t, Curve2D& c1, Curve2D& c2) const {
    // Not implemented
}


//*************************************************************************
// Manipulation procedures
//*************************************************************************

/*
 * function: addAnchor
 *
 * Adds an anchor point at the given index.
 *
 * Args:
 *   position: the position of the new anchor point
 *   i: the index at which to insert the point
 *
 * Throws:
 *   std::out_of_range if 0 <= i <= anchorCount() is not satisfied
 */
void Curve2D::addAnchor(bezVect2D position, std::size_t i) {
    // Not implemented
}

/*
 * function: removeAnchor
 *
 * Removes the anchor point at the given index from the spline.
 *
 * Args:
 *   i: the index of the anchor point to remove
 *
 * Throws:
 *   std::out_of_range if 0 <= i < anchorCount() is not satisfied
 */
void Curve2D::removeAnchor(std::size_t i) {
    // Not implemented
}

/*
 * function: setAnchor
 *
 * Sets the new position of the anchor point at the given index.
 *
 * Args:
 *   position: new position for the anchor point
 *   i: index of anchor point to move
 *
 * Throws:
 *   std::out_of_range if 0 <= i < anchorCount() is not satisfied
 */
void Curve2D::setAnchor(bezVect2D position, std::size_t i) {
    points[i * 3] = position;
}

/*
 * function: moveAnchor
 *
 * Translates the given anchor point by the given offset.
 *
 * Args:
 *   offset: displacement to apply to anchor point
 *   i: index of anchor point to move
 *
 * Throws:
 *   std::out_of_range if 0 <= i < anchorCount() is not satisfied
 */
void Curve2D::moveAnchor(bezVect2D offset, std::size_t i) {
    // Not implemented
}

/*
 * function: clear
 *
 * Removes all anchor points from the spline.
 */
void Curve2D::clear(void) {
    // Not implemented
}


//*****************************************************************************
// Hidden procedures
//*****************************************************************************

/*
 * function: updateControlPoints
 *
 * Sets the positions of the control points to ensure C2 continuity.
 */
void Curve2D::updateControlPoints(void) {
    std::size_t i;  // i stores index of anchor point
    std::size_t j;  // j stores index of anchor point in `points`
    std::size_t k;
    BEZ_DTYPE inv_b;

    if (anchor_count <= 1)
        return;

    if (anchor_count == 2) {
        points[1][0] = points[0][0];
        points[1][1] = points[0][1];

        points[2][0] = points[3][0];
        points[2][1] = points[3][1];
        
        return;
    }

    // Calculate positions of B_points
    B_points[0][0] = points[0][0];
    B_points[0][1] = points[0][1];

    B_points[anchor_count - 1][0] = points[points.size() - 1][0];
    B_points[anchor_count - 1][1] = points[points.size() - 1][1];
    
    c[1] = 0.25;

    B_points[1][0] = c[1] * (6. * points[3][0] - points[0][0]);
    B_points[1][1] = c[1] * (6. * points[3][1] - points[0][1]);

    for (i = 2, j = 6; i < anchor_count - 2; i++, j += 3) {
        c[i] = 1. / (4. - c[i - 1]);

        B_points[i][0] = c[i] * (6. * points[j][0] - B_points[i - 1][0]);
        B_points[i][1] = c[i] * (6. * points[j][1] - B_points[i - 1][1]);
    }

    i = anchor_count - 2;
    j = points.size() - 1;
    c[i] = 1. / (4. - c[i - 1]);

    B_points[i][0] = c[i] * (6. * points[j - 3][0] - points[j][0] - B_points[i - 1][0]);
    B_points[i][1] = c[i] * (6. * points[j - 3][1] - points[j][1] - B_points[i - 1][1]);

    for (i = anchor_count - 3; i > 0; i--) {
        B_points[i][0] -= c[i] * B_points[i + 1][0];
        B_points[i][1] -= c[i] * B_points[i + 1][1];
    }

    // Calculate positions of control points
    i = 1;
    j = 0;
    while (i < points.size()) {
        points[i][0] = BEZ_TWO_THIRDS * B_points[j][0] + BEZ_ONE_THIRD * B_points[j + 1][0];
        points[i][1] = BEZ_TWO_THIRDS * B_points[j][1] + BEZ_ONE_THIRD * B_points[j + 1][1];

        i++;

        points[i][0] = BEZ_ONE_THIRD * B_points[j][0] + BEZ_TWO_THIRDS * B_points[j + 1][0];
        points[i][1] = BEZ_ONE_THIRD * B_points[j][1] + BEZ_TWO_THIRDS * B_points[j + 1][1];

        i += 2;
        j++;
    }
}
