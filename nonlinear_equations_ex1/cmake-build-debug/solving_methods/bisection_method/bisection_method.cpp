//
// Created by alyona on 12.02.23.
//
#include "bisection_method.h"

Bisection::Bisection(double start, double end, double e): NonlinearEq(start, end, e) {
    result = solution();
}

double Bisection::solution() {
    double solve = (b + a) / 2;
    iter_count = 0;
    while (abs(f(solve)) >= epsilon) {
        iter_count++;
        if (f(a) * f (solve) < 0) {
            b = solve;
            solve = (b + a) / 2;
        } else if (f(solve) * f (b) < 0) {
            a = solve;
            solve = (b + a) / 2;
        }
        if (f(a) == 0) {
            return a;
        }
        if (f(b) == 0) {
            return b;
        }
    }
    return solve;
}
