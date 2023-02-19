//
// Created by Алёна on 19.02.2023.
//


/*
 * Достаточное условие сходимости:
 * |psi'(x)| = |1 - lambda0 * f'(x)| <= gamma < 1
 *
 * */

#ifndef NUMERICAL_METHODS_NSU_2_SIMPLE_ITERATION_METHOD_H
#define NUMERICAL_METHODS_NSU_2_SIMPLE_ITERATION_METHOD_H

#include "nonlinear_equation.h"

class simple_iteration_method: public nonlinear_equation {
private:
    double psi(double x);
public:
    double solution(double a, double b) override;
};


#endif //NUMERICAL_METHODS_NSU_2_SIMPLE_ITERATION_METHOD_H
