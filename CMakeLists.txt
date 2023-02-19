cmake_minimum_required(VERSION 3.24)
project(Numerical_methods_NSU_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Numerical_methods_NSU_2 main.cpp methods/bisection_method.cpp methods/bisection_method.h methods/simple_iteration_method.cpp methods/simple_iteration_method.h methods/relaxation_method.cpp methods/relaxation_method.h methods/newton_method.cpp methods/newton_method.h methods/nonlinear_equation.cpp methods/nonlinear_equation.h)
