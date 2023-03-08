//
// Created by Алёна on 19.02.2023.
//

#ifndef NUMERICAL_METHODS_NSU_2_NONLINEAR_EQUATION_H
#define NUMERICAL_METHODS_NSU_2_NONLINEAR_EQUATION_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

class nonlinear_equation {
protected:
    double epsilon = 1e-9; //погрешность
    int sign(double x);      //определение знака числа x
    int iter_count;        //количество итераций
    double df(double x);     //производная функции f в точке x
    double f(double x);
    virtual double solution(double start, double end) = 0; //решение уравнения f(x) = 0 на отрезке [start, end]
public:
    void print_res(double start, double end, string name = ""); //печать решения
};

#endif //NUMERICAL_METHODS_NSU_2_NONLINEAR_EQUATION_H
