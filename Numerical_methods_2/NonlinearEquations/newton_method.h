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
    double psi(double);
    double solution(double, double) override;
public:
};


#endif //NUMERICAL_METHODS_NSU_2_NEWTON_METHOD_H
