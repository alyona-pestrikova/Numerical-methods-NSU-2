//
// Created by Алёна on 02.03.2023.
//

#ifndef NUMERICAL_METHODS_NSU_2_NEWTON_METHOD_SYSTEM_H
#define NUMERICAL_METHODS_NSU_2_NEWTON_METHOD_SYSTEM_H

#include "nonlinear_system.h"
#include "gauss_method.h"

class newton_method_system: public nonlinear_system {
private:
    double* get_res(double*) override;
    double** jacoby_mx(double*);
public:
    explicit newton_method_system(double*);
};


#endif //NUMERICAL_METHODS_NSU_2_NEWTON_METHOD_SYSTEM_H
