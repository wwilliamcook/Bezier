cmake_minimum_required(VERSION 3.1)

project(Bezier)

add_subdirectory(deps/GLEW/build/cmake)
add_subdirectory(deps/GLFW)

add_library(Curve src/curve.cpp)
target_include_directories(Curve PUBLIC include)

add_library(Display src/display.cpp)
target_include_directories(Display PUBLIC include
                           deps/GLEW/include
                           deps/GLFW/include)
target_link_libraries(Display
                      glew_s
                      glfw)

add_executable(Bezier src/main.cpp)
target_link_libraries(Bezier Curve Display)

add_executable(CurveTest test/curve_test.cpp)
target_link_libraries(CurveTest Curve Display)
