//
// Created by alyona on 12.02.23.
//

/*
 * Метод простой итерации: x = psi(x), где psi(x) = x - tau(x) * f(x).
 *
 * Оптимальный параметр tau(x) = 1/f'(x). Вместо него можно взять константу того же знака, что и производная в окрестности корня.
 *
 * Достаточное условие сходимости: |psi'(x)| = |1 - tau * f'(x)| <= gamma < 1 или, что эквивалентно, -gamma + 1 <= tau*f'(x) <= gamma + 1.
 *
 */

#ifndef NONLINEAR_EQUATIONS_EX1_SIMPLE_ITERATION_H
#define NONLINEAR_EQUATIONS_EX1_SIMPLE_ITERATION_H

#pragma once

#include "../NonlinearEq.h"
#include <iostream>
#include <cmath>
using namespace std;

class SimpleIter: public NonlinearEq {
private:
    double solution() override;
    double psi(double x);
public:
    SimpleIter(double start, double end, double e);
};

#endif //NONLINEAR_EQUATIONS_EX1_SIMPLE_ITERATION_H
