#include <iostream>

#include "nonlinear_eq_solving/bisection_method.h"
#include "nonlinear_eq_solving/newton_method.h"
#include "nonlinear_eq_solving/simple_iteration_method.h"
#include "nonlinear_eq_solving/relaxation_method.h"

using namespace std;

int main() {

    double a = -7;
    double b = -4;


    bisection_method bis;
    simple_iteration_method simp;
    newton_method newton;

    cout << "Bisection method: \n\tresult: " << bis.solution(a, b) << "\n\tcount of iterations:" << bis.get_iter_cunt() << endl;
    cout << "Simple iteration method: \n\tresult: " << simp.solution(a, b) << "\n\tcount of iterations:" << simp.get_iter_cunt() << endl;
    cout << "Newton method: \n\tresult: " << newton.solution(a, b) << "\n\tcount of iterations:" << newton.get_iter_cunt() << endl;

    return 0;
}
