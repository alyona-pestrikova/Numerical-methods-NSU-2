//
// Created by Алёна on 19.02.2023.
//

#include "simple_iterations_system.h"

double *simple_iterations_system::psi(double *par) {
    double* res = new double [size];

    //for (int i = 0; i < size; i++) { // - это не работает
     //   res[i] = par[i] - (system(par))[i];
    //}

    //res[0] = pow((8 * par[0] * par[1] - pow(par[1], 3)), 0.33);
    //res[1] = par[1] + par[1] / log(par[1]) - par[0] / log(par[0]);

    double d = 1.0 / 3.0;
    res[0] = 4;
    res[1] = pow((res[0] + 3), d);

    return res;
}

//par - начальное приближение
double *simple_iterations_system::get_res(double *par) {
    iter_count = 1;
    double* prev = par;
    double* res = psi(par);
    while (max_diff(prev, res) > epsilon) {
        prev = res;
        res = psi(prev);
        iter_count++;
    }
    return res;
}

simple_iterations_system::simple_iterations_system(double *par) {
    result = new double[size];
    double* res = get_res(par);
    for (int i = 0; i < size; i++) {
        result[i] = res[i];
    }
}








