//
// Created by Алёна on 19.02.2023.
//

#ifndef NUMERICAL_METHODS_NSU_2_NEWTON_METHOD_H
#define NUMERICAL_METHODS_NSU_2_NEWTON_METHOD_H

#include "nonlinear_equation.h"
#include <iostream>

using namespace std;

class newton_method: public nonlinear_equation {
private:
    double psi(double x);
public:
    double solution(double a, double b) override;
};


#endif //NUMERICAL_METHODS_NSU_2_NEWTON_METHOD_H
