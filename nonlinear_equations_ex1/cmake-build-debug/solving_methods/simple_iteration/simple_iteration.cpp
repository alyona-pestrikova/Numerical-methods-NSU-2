//
// Created by alyona on 12.02.23.
//
#include "simple_iteration.h"

double SimpleIter::psi(double x) {
    return x + 0.16 * f(x);
}

double SimpleIter::solution() {
    iter_count = 0;
    double solve = psi(b);
    while (abs(f(solve)) >= epsilon) {
        iter_count++;
        solve = psi(solve);
    }
    return solve;
}

SimpleIter::SimpleIter(double start, double end, double e) : NonlinearEq(start, end, e) {
    result = solution();
}
