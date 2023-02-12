//
// Created by alyona on 12.02.23.
//


/*
 * Метод бисекций всегда сходится, то есть при его использовании решение получается всегда, причем с заданной точностью.
 * После каждой итерации, отрезок, на котором расположен корень, уменьшается вдвое, то есть после n итераций он сокращается в 2^n раз.
 *
 */

#ifndef NONLINEAR_EQUATIONS_EX1_BISECTION_METHOD_H
#define NONLINEAR_EQUATIONS_EX1_BISECTION_METHOD_H

#pragma once

#include "../NonlinearEq.h"
#include <iostream>
#include <cmath>
using namespace std;

class Bisection: public NonlinearEq {
private:
    double solution() override;
public:
    Bisection(double start, double end, double e);
};

/*class Bisection {
private:
    double f (double x);
    double a;
    double b;
    double epsilon;
    double result;
    int iter_count;
    double solution();
public:
    Bisection(double start, double end, double e);
    double get_result();
    double get_fun_res();
    int get_iter_count();
};*/

#endif //NONLINEAR_EQUATIONS_EX1_BISECTION_METHOD_H
