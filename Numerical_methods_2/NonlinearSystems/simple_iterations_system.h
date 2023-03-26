//
// Created by Алёна on 19.02.2023.
//

#ifndef NUMERICAL_METHODS_NSU_2_SIMPLE_ITERATIONS_SYSTEM_H
#define NUMERICAL_METHODS_NSU_2_SIMPLE_ITERATIONS_SYSTEM_H


#include "nonlinear_system.h"
#include <cmath>

class simple_iterations_system: public nonlinear_system {
private:
    double * get_res(double*) override;
    double* psi (double*);
public:
    explicit simple_iterations_system(double*);
};


#endif //NUMERICAL_METHODS_NSU_2_SIMPLE_ITERATIONS_SYSTEM_H
