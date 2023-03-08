//
// Created by Алёна on 02.03.2023.
//

#include "newton_method_system.h"
#include <iomanip>

double **newton_method_system::jacoby_mx(double* x) {
    double** mx = new double*[size];
    for (int i = 0; i < size; i++) {
        mx[i] = new double [size];
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            double* x1 = new double[2];
            x1[0] = x[0];
            x1[1] = x[1];
            x1[j] += epsilon;
            mx[i][j] = (system(x1)[i] - system(x)[i]) / epsilon;
        }
    }

    return mx;
}

newton_method_system::newton_method_system(double * par) {
    result = new double[size];
    double* res = get_res(par);
    for (int i = 0; i < size; i++) {
        result[i] = res[i];
    }
}

double *newton_method_system::get_res(double * par) {
    iter_count = 0;
    double* prev = new double[size];
    double* res = par;
    double* vec;

     do {
        for (int i = 0; i < size; i++) {
            prev[i] = res[i];
        }
        vec = system(prev);
        for (int i = 0; i < size; i++) {
            vec[i] *= (-1);
        }
        gauss_method gauss(size, jacoby_mx(prev), vec);

        double* b = gauss.get_res();

        for (int i = 0; i < size; i++) {
            res[i] = prev[i] + b[i];
        }
        iter_count++;
    } while (max_diff(prev, res) > epsilon);
    return res;
}
