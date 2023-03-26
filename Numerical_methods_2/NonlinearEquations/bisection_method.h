//
// Created by Алёна on 19.02.2023.
//

#ifndef NUMERICAL_METHODS_NSU_2_BISECTION_METHOD_H
#define NUMERICAL_METHODS_NSU_2_BISECTION_METHOD_H

#include "nonlinear_equation.h"


class bisection_method: public nonlinear_equation {
private:
    double solution(double, double) override;
public:
};


#endif //NUMERICAL_METHODS_NSU_2_BISECTION_METHOD_H
