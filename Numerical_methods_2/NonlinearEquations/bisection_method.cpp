//
// Created by Алёна on 19.02.2023.
//

#include "bisection_method.h"

using namespace std;

double bisection_method::solution(double a, double b) {
    iter_count = 0;
    double x0 = (a + b) / 2;

    while ((b - a) > 2 * epsilon) {
        if (f(x0) == 0) {
            return x0;
        }

        if (sign(f(x0)) == sign(f(a))) {
            a = x0;
        } else {
            b = x0;
        }

        x0 = (a + b) / 2;
        iter_count++;
    }

    return x0;
}

//bisection_method::bisection_method(double a, double b): nonlinear_equation(a, b) {}
