cmake_minimum_required(VERSION 3.23)
project(nonlinear_equations_ex1)

set(CMAKE_CXX_STANDARD 14)

add_executable(nonlinear_equations_ex1 main.cpp cmake-build-debug/solving_methods/bisection_method/bisection_method.h cmake-build-debug/solving_methods/bisection_method/bisection_method.cpp cmake-build-debug/solving_methods/simple_iteration/simple_iteration.h cmake-build-debug/solving_methods/simple_iteration/simple_iteration.cpp cmake-build-debug/solving_methods/NonlinearEq.cpp cmake-build-debug/solving_methods/NonlinearEq.h cmake-build-debug/solving_methods/newton_method/newton_method.cpp cmake-build-debug/solving_methods/newton_method/newton_method.h)
