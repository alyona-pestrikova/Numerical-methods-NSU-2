//
// Created by alyona on 12.02.23.
//

#ifndef NONLINEAR_EQUATIONS_EX1_NONLINEAREQ_H
#define NONLINEAR_EQUATIONS_EX1_NONLINEAREQ_H

#pragma once

#include <iostream>
#include <cmath>

class NonlinearEq {
protected:
    double f (double x);
    double a;
    double b;
    double epsilon;
    double result;
    int iter_count = 0;
    virtual double solution() = 0;
public:
    NonlinearEq(double start, double end, double e);
    double get_result();
    double get_fun_res();
    int get_iter_count();
};

#endif //NONLINEAR_EQUATIONS_EX1_NONLINEAREQ_H
