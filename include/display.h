/*
 * display.h
 *
 * Distributed under the Apache Licence 2.0
 *
 * Defines the interface for the display.
 */

#ifndef BEZIER_DISPLAY_H
#define BEZIER_DISPLAY_H

#include "tuple.h"


class BezierDisplay2D {

public:
    BezierDisplay2D(int width, int height);
    void drawCurve(const Tuple<2> p[4]);
    void show(void);
};

class BezierDisplay3D {

public:
    BezierDisplay3D(int width, int height);
    void drawCurve(const Tuple<3> p[4]);
    void drawSurface(const Tuple<3> p[16]);
    void show(void);
};

#endif
