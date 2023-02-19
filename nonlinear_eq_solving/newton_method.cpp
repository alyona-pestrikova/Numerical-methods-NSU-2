//
// Created by Алёна on 19.02.2023.
//

#include "newton_method.h"

double newton_method::psi(double x) {
    return x - f(x) / df(x);
}

double newton_method::solution(double a, double b) {
    double x0 = (a + b) / 2;
    double x1 = psi(x0);
    iter_count = 1;

    while (abs(x1 - x0) > epsilon) {
        x0 = x1;
        x1 = psi(x0);
        iter_count++;
    }

    return x1;
}
