//
// Created by alyona on 12.02.23.
//

#include "newton_method.h"

double Newton::solution() {
    double solve = (a + b) / 2;
    iter_count = 0;
    while (fabs(f(solve)) > epsilon) {
        iter_count++;
        solve = psi(solve);
    }
    return solve;
}

Newton::Newton(double start, double end, double e) : NonlinearEq(start, end, e) {
    result = solution();
}

double Newton::df(double x) {
    return 2 * x;
}

double Newton::psi(double x) {
    return x - f(x) / df(x);
}
