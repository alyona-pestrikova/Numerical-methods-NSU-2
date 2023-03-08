//
// Created by Алёна on 19.02.2023.
//

#ifndef NUMERICAL_METHODS_NSU_2_NONLINEAR_SYSTEM_H
#define NUMERICAL_METHODS_NSU_2_NONLINEAR_SYSTEM_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
#include <string>

using namespace std;

class nonlinear_system {
protected:
    double epsilon = 1e-9;
    int size = 2;
    int iter_count;
    double * system (double*) const;
    double * result;
    virtual double* get_res(double*) = 0;
    double max_diff(double*, double*); //максимальный модуль разности компонент векторов
public:
    void print_res(string name = "");
    ~nonlinear_system();
};


#endif //NUMERICAL_METHODS_NSU_2_NONLINEAR_SYSTEM_H
