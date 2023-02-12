//
// Created by alyona on 12.02.23.
//

#include "NonlinearEq.h"
#include <iostream>
using namespace std;


double NonlinearEq::f(double x) {
    return x * x - 9;
}

NonlinearEq::NonlinearEq(double start, double end, double e) {
    a = start;
    b = end;
    epsilon = e;
}

double NonlinearEq::solution() {
    return 0;
}

double NonlinearEq::get_result() {
    return result;
}

double NonlinearEq::get_fun_res() {
    return f(result);
}

int NonlinearEq::get_iter_count() {
    return iter_count;
}





