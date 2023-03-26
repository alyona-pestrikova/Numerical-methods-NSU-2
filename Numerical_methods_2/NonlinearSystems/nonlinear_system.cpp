//
// Created by Алёна on 19.02.2023.
//

#include "nonlinear_system.h"


double* nonlinear_system::system(double *par) const {
    double* res = new double[size];

    //начальное приближение : 3.8, 2
    //res[0] = pow(par[0], 3) + pow(par[1], 3)  - 8 * par[0] * par[1];
    //res[1] = par[0] * log(par[1]) - par[1] * log(par[0]);

    res[0] = par[0] - pow(par[1], 3) + 3;
    res[1] = par[0] - 4;

    return res;
}

void nonlinear_system::print_res(string name) {
    if (name != "") {
        cout << setw(10) << name << ": ";
    }
    for (int i = 0; i < size; i++) {
        cout << setw(9) << result[i] << " ";
    }
    cout << " | Count of iterations: ";
    cout << setw(4) << iter_count;
    cout << " | f(result) = ";
    for (int i = 0; i < size; i++) {
        cout << setw(12) << system(result)[i] << " ";
    }
    cout << endl;
}

double nonlinear_system::max_diff(double *vec1, double *vec2) {
    double max = 0;
    for (int i = 0; i < size; i++) {
        if (abs(vec1[i] - vec2[i]) > max) max = abs(vec1[i] - vec2[i]);
    }
    return max;
}

nonlinear_system::~nonlinear_system() {
    delete[] result;
}
