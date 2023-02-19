//
// Created by Алёна on 19.02.2023.
//

#ifndef NUMERICAL_METHODS_NSU_2_NONLINEAR_EQUATION_H
#define NUMERICAL_METHODS_NSU_2_NONLINEAR_EQUATION_H

#include <cmath>

class nonlinear_equation {
protected:
    double epsilon = 0.000000001;
    double f(double x);
    int sign(double x);
    int iter_count;
    double df(double x);
public:
    virtual double solution(double a, double b) = 0;
    int get_iter_cunt();
};

#endif //NUMERICAL_METHODS_NSU_2_NONLINEAR_EQUATION_H
