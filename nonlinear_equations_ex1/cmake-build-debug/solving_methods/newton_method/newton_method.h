//
// Created by alyona on 12.02.23.
//

#ifndef NONLINEAR_EQUATIONS_EX1_NEWTON_METHOD_H
#define NONLINEAR_EQUATIONS_EX1_NEWTON_METHOD_H

#pragma once

#include "../NonlinearEq.h"
#include <iostream>
#include <cmath>

class Newton: public NonlinearEq {
private:
    double solution() override;
    double df(double x); //производная функции f
    double psi(double x);
public:
    Newton(double start, double end, double e);
};

#endif //NONLINEAR_EQUATIONS_EX1_NEWTON_METHOD_H
