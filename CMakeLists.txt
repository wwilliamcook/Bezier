cmake_minimum_required(VERSION 3.1)

project(Bezier)


###############################################################################
# DEPENDENCIES
###############################################################################

add_subdirectory(deps/GLEW/build/cmake)
add_subdirectory(deps/GLFW)


###############################################################################
# LIBRARIES
###############################################################################

add_library(Bezier src/bezier.c)
target_include_directories(Bezier PRIVATE include)

add_library(Curve src/curve.cpp)
target_include_directories(Curve PRIVATE include)
target_link_libraries(Curve Bezier)


###############################################################################
# TESTS
###############################################################################


###############################################################################
# EXAMPLES
###############################################################################

add_executable(Example-SingleBezierVisualization examples/single_cubic_bezier_curve_visualization.cpp)
target_include_directories(Example-SingleBezierVisualization PRIVATE
                           include
                           deps/GLEW/include
                           deps/GLFW/include)
target_link_libraries(Example-SingleBezierVisualization
                      glew_s
                      glfw)

add_executable(Example-FiveAnchorVisualization examples/5_anchor_visualization.cpp)
target_include_directories(Example-FiveAnchorVisualization PRIVATE
                           include
                           deps/GLEW/include
                           deps/GLFW/include)
target_link_libraries(Example-FiveAnchorVisualization
                      Curve
                      glew_s
                      glfw)
