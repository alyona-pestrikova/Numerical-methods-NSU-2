//
// Created by Алёна on 19.02.2023.
//

#include "nonlinear_equation.h"

double nonlinear_equation::f(double x) {
    return cos(x);
};

int nonlinear_equation::sign(double x) {
    if (x == 0) {
        return 0;
    } else if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

int nonlinear_equation::get_iter_cunt() {
    return iter_count;
}

double nonlinear_equation::df(double x) {
    return (f(x + epsilon) - f(x)) / epsilon;
}
