#include <iostream>

#include "nonlinear_eq_solving/bisection_method.h"
#include "nonlinear_eq_solving/newton_method.h"
#include "nonlinear_eq_solving/simple_iteration_method.h"
#include "nonlinear_eq_system_solving/simple_iterations_system.h"
#include "nonlinear_eq_system_solving/gauss_method.h"
#include "nonlinear_eq_system_solving/newton_method_system.h"
using namespace std;

int main() {

    setlocale(LC_ALL, "ru");

    double a = -1;
    double b = 0;


    /*bisection_method bis;
    simple_iteration_method simp;
    newton_method newton;

    cout << "Bisection method: \n\tresult: " << bis.solution(a, b) << "\n\tcount of iterations:" << bis.get_iter_cunt() << endl;
    cout << "Simple iteration method: \n\tresult: " << simp.solution(a, b) << "\n\tcount of iterations:" << simp.get_iter_cunt() << endl;
    cout << "Newton method: \n\tresult: " << newton.solution(a, b) << "\n\tcount of iterations:" << newton.get_iter_cunt() << endl;*/

    /*double* par = new double[2];
    par[0] = 3.8;
    par[1] = 2;
    simple_iterations_system sys(par);
    sys.print_res("Simple iteration");*/

    /*double** mx = new double*[5];
    double* vec = new double[5];
    for (int i = 0; i < 5; i++) {
        mx[i] = new double[5];
        vec[i] = i;
        for (int j = 0; j < 5; j++) {
            mx[i][j] = exp(i * j);
        }
    }

    try {
        gauss_method g(5, mx, vec);
    } catch (const char* s) {
        cout << s;
    }*/

    bisection_method bis;
    simple_iteration_method simple_eq;
    newton_method newton_eq;

    cout << endl << "Nonlinear equations:\n";
    bis.print_res(a, b, "BISECTION");
    simple_eq.print_res(a, b, "SIMPLE");
    newton_eq.print_res(a, b, "NEWTON");


    double* par = new double[1]; //задаем начальное приближение для систем
    par[0] = -1;
    par[1] = 4;
    simple_iterations_system simp_s(par);
    newton_method_system newton_s(par);

    cout << endl << "Nonlinear systems:\n";
    simp_s.print_res("SIMPLE");
    newton_s.print_res("NEWTON");

    return 0;
}
