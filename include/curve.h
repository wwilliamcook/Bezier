/*
 * curve.h
 *
 * Defines the interface for the classes Curve2D and Curve3D.
 */

#ifndef BEZIER_CURVE_H
#define BEZIER_CURVE_H

#include <array>
#include <vector>

//#define BEZ_DIMS 2
#define BEZ_DTYPE float


typedef std::array<BEZ_DTYPE, 2> bezVect2D;
typedef std::array<BEZ_DTYPE, 3> bezVect3D;


//*****************************************************************************
//* CURVE2D
//*****************************************************************************

/*
 * class: Curve2D
 *
 * Implements a cubic Bezier spline with C2 continuity. Interface allows
 * interaction with the anchor points, and the control points are determined
 * internally.
 */
class Curve2D {
public:
    //*************************************************************************
    // Constructors/Destructors
    //*************************************************************************

    /*
     * default constructor
     *
     * Constructs an empty spline.
     */
    Curve2D(void);

    /*
     * constructor
     *
     * Constructs a spline from the given anchor points.
     *
     * Args:
     *   anchor_points: ordered anchor points from which to construct spline
     */
    Curve2D(const std::vector<bezVect2D>& anchor_points);


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
    bezVect2D getPositionAt(BEZ_DTYPE t) const;

    /*
     * function: anchorCount
     *
     * Returns the number of anchor points.
     */
    std::size_t anchorCount(void) const;

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
    const bezVect2D& getAnchor(std::size_t i) const;

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
    BEZ_DTYPE getLength(BEZ_DTYPE t0, BEZ_DTYPE t1) const;

    /*
     * function: getLength
     *
     * Returns the total length of the spline.
     */
    BEZ_DTYPE getLength(void) const;

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
    void split(BEZ_DTYPE t, Curve2D& c1, Curve2D& c2) const;


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
    void addAnchor(bezVect2D position, std::size_t i);

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
    void removeAnchor(std::size_t i);

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
    void setAnchor(bezVect2D position, std::size_t i);

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
    void moveAnchor(bezVect2D offset, std::size_t i);

    /*
     * function: clear
     *
     * Removes all anchor points from the spline.
     */
    void clear(void);
    

//private:
    //*************************************************************************
    // Hidden procedures
    //*************************************************************************

    /*
     * function: updateControlPoints
     *
     * Sets the positions of the control points to ensure C2 continuity.
     */
    void updateControlPoints(void);


    //*************************************************************************
    // Internal attributes
    //*************************************************************************
    std::size_t anchor_count;  // Number of anchor points in the spline
    std::size_t bezier_count;  // Number of bezier curves in the spline

    std::vector<bezVect2D> points;  // Must contain
                                                          // 3n + 1 points for
                                                          // n anchor points
    std::vector<bezVect2D> B_points;  // Contains n points
                                                            // Used to create
                                                            // B-spline curve
    std::vector<BEZ_DTYPE> c;  // Contains n values
                               // Used for calculating B-spline points
};


//*****************************************************************************
//* CURVE3D
//*****************************************************************************

/*
 * class: Curve3D
 *
 * Implements a cubic Bezier spline with C2 continuity. Interface allows
 * interaction with the anchor points, and the control points are determined
 * internally.
 */
class Curve3D {
public:
    //*************************************************************************
    // Constructors/Destructors
    //*************************************************************************

    /*
     * default constructor
     *
     * Constructs an empty spline.
     */
    Curve3D(void);

    /*
     * constructor
     *
     * Constructs a spline from the given anchor points.
     *
     * Args:
     *   anchor_points: ordered anchor points from which to construct spline
     */
    Curve3D(const std::vector<bezVect3D>& anchor_points);


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
    bezVect3D getPositionAt(BEZ_DTYPE t) const;

    /*
     * function: anchorCount
     *
     * Returns the number of anchor points.
     */
    std::size_t anchorCount(void) const;

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
    const bezVect3D& getAnchor(std::size_t i) const;

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
    BEZ_DTYPE getLength(BEZ_DTYPE t0, BEZ_DTYPE t1) const;

    /*
     * function: getLength
     *
     * Returns the total length of the spline.
     */
    BEZ_DTYPE getLength(void) const;

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
    void split(BEZ_DTYPE t, Curve3D& c1, Curve3D& c2) const;


    //*************************************************************************
    // Manipulation procedures
    //*************************************************************************

    /*
     * function: addPoint
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
    void addPoint(bezVect3D position, std::size_t i);

    /*
     * function: removePoint
     *
     * Removes the anchor point at the given index from the spline.
     *
     * Args:
     *   i: the index of the anchor point to remove
     *
     * Throws:
     *   std::out_of_range if 0 <= i < anchorCount() is not satisfied
     */
    void removePoint(std::size_t i);

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
    void setAnchor(bezVect3D position, std::size_t i);

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
    void moveAnchor(bezVect3D offset, std::size_t i);

    /*
     * function: clear
     *
     * Removes all anchor points from the spline.
     */
    void clear(void);
    

//private:
    //*************************************************************************
    // Hidden procedures
    //*************************************************************************

    /*
     * function: updateControlPoints
     *
     * Sets the positions of the control points to ensure C2 continuity.
     */
    void updateControlPoints(void);


    //*************************************************************************
    // Internal attributes
    //*************************************************************************
    std::size_t anchor_count;  // Number of anchor points in the spline
    std::size_t bezier_count;  // Number of bezier curves in the spline

    std::vector<bezVect3D> points;  // Must contain
                                                          // 3n + 1 points for
                                                          // n anchor points
    std::vector<bezVect3D> B_points;  // Contains n points
                                                            // Used to create
                                                            // B-spline curve
    std::vector<BEZ_DTYPE> c;  // Contains n values
                               // Used for calculating B-spline points
};

#endif
