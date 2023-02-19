//
// Created by Алёна on 19.02.2023.
//

#include "simple_iteration_method.h"
#include <iostream>

using namespace std;

//здесь f(x) нужно умножить на константу, совпадающую по знаку с производной ф-ии f в окрестности корня
double simple_iteration_method::psi(double x) {
    return x + f(x);
}

double simple_iteration_method::solution(double a, double b) {
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