# Bezier

Library for working with Bezier splines. Build target `Curve` creates a static library. See `include/curve.h`.

## Requirements

Building requires [CMake](https://cmake.org/) and a compatible C/C++ compiler.

## Dependencies

* [GLEW](https://github.com/nigels-com/glew)
* [GLFW](https://www.glfw.org/)

## Building

* Download [GLEW source code](https://github.com/nigels-com/glew#downloads) and extract into `/deps`, renaming to `/deps/GLEW`.
* Download [GLFW source code](https://www.glfw.org/download.html) and extract into `/deps`, renaming to `/deps/GLFW`.
* Build with CMake
* Compile

## References
* Many thanks to [this](https://pomax.github.io/bezierinfo/) fantastic article on Bezier curves.
