#include <iostream>
#include <cmath>
#include "cmake-build-debug/solving_methods/simple_iteration/simple_iteration.h"
#include "cmake-build-debug/solving_methods/bisection_method/bisection_method.h"
#include "cmake-build-debug/solving_methods/newton_method/newton_method.h"
using namespace std;

int main() {

    //отрезок
    double a = -3;
    double b = 2;

    double epsilon = 0.0000001;

    SimpleIter solve1(a, b, epsilon);
    Bisection solve2(a, b, epsilon);
    Newton solve3(a, b, epsilon);

    cout << "Simple iteration:\n";
    cout << "\tSolution: " << solve1.get_result() <<  endl;
    cout << "\tFunction of the solution:" << solve1.get_fun_res() << endl;
    cout << "\tCount of iterations: " << solve1.get_iter_count() <<  endl;

    cout << endl;

    cout << "Bisection method:\n";
    cout << "\tSolution 2: " << solve2.get_result() <<  endl;
    cout << "\tFunction of the solution 2:" << solve2.get_fun_res() << endl;
    cout << "\tCount of iterations 2: " << solve2.get_iter_count() <<  endl;

    cout << endl;

    cout << "Newton method:\n";
    cout << "\tSolution 2: " << solve3.get_result() <<  endl;
    cout << "\tFunction of the solution 2:" << solve3.get_fun_res() << endl;
    cout << "\tCount of iterations 2: " << solve3.get_iter_count() <<  endl;

    return 0;
}
