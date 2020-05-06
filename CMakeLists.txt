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

add_library(Bezier src/bezier.c include/bezier.h)
target_include_directories(Bezier PRIVATE include)

add_library(Curve src/curve.cpp include/curve.h)
target_include_directories(Curve PRIVATE include)
target_link_libraries(Curve Bezier)


###############################################################################
# TESTS
###############################################################################

add_executable(test-bezier_library test/bezier_test.c)
target_include_directories(test-bezier_library PRIVATE include)
target_link_libraries(test-bezier_library Bezier)


###############################################################################
# EXAMPLES
###############################################################################

add_executable(Example-SingleBezierVisualization examples/single_cubic_bezier_curve_visualization.cpp)
target_include_directories(Example-SingleBezierVisualization PRIVATE
                           include
                           deps/GLEW/include
                           deps/GLFW/include)
target_link_libraries(Example-SingleBezierVisualization
                      Bezier
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


###############################################################################
# BENCHMARKS
###############################################################################

add_executable(benchmark-bezier_library benchmarks/bezier_benchmark.c)
target_include_directories(benchmark-bezier_library PRIVATE include benchmarks/include)
target_link_libraries(benchmark-bezier_library Bezier)

add_executable(benchmark-float benchmarks/float_benchmark.c)
target_include_directories(benchmark-float PRIVATE benchmarks/include)

