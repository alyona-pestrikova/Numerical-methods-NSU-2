// Numerical_methods_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

//#include "Graphic/graphic.h"
#include "CauchyProblem/AdamsBashfortMethod.h"
#include "CauchyProblem/EulerMethod.h"
#include "CauchyProblem/RungeKuttaMethod.h"
#include "Integral/Integral.h"

float fun(float x) {
	return cos(x);
}

int main() 
{

	Integral in(fun);
	pair res = in.rectangle_method(0, M_PI / 2, 1e-5, 'l');
	std::cout << res.res << " " << res.steps_count << std::endl;
	pair res1 = in.trapetion_method(0, M_PI / 2, 1e-5);
	std::cout << res1.res << " " << res1.steps_count << std::endl;
	pair res2 = in.simpson_method(0, M_PI / 2, 1e-5);
	std::cout << res2.res << " " << res2.steps_count << std::endl;
	return 0;
}