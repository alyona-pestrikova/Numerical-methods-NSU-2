//
// Created by Алёна on 19.02.2023.
//

#include "bisection_method.h"
#include "iostream"

using namespace std;

double bisection_method::solution(double a, double b) {
    iter_count = 0;
    double x0 = (a + b) / 2;

    while ((b - a) > epsilon) {
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
