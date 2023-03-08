//
// Created by Алёна on 19.02.2023.
//

#include "nonlinear_equation.h"

double nonlinear_equation::f(double x) {
    return pow(x, 3) - 0.2 * pow(x, 2) + 0.5 * x + 1.5;
};

int nonlinear_equation::sign(double x) {
    if (x == 0) {
        return 0;
    } else if (x > 0) {
        return 1;
    } else {
        return -1;
    }
}

double nonlinear_equation::df(double x) {
    return (f(x + epsilon) - f(x)) / epsilon;
}

void nonlinear_equation::print_res(double start, double end, string name) {

    if (name != "") {
        cout << setw(10) << name << ": ";
    }
    double res = solution(start, end);
    cout << setw(9) << res;
    cout << " | Count of iterations: ";
    cout << setw(4) << iter_count;
    cout << " | f(result) = " << f(res);
    cout << endl;
}



