// Numerical_methods_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS


//#include "Graphic/graphic.h"
#include "CauchyProblem/AdamsBashfortMethod.h"
#include "CauchyProblem/EulerMethod.h"
#include "CauchyProblem/RungeKuttaMethod.h"

int main(int argc, char** argv) 
{

	EulerMethod euler(0, 0, 70, 10);
	euler.print_res("EULER METHOD");

	RungeKuttaMethod rkm(0, 0, 70, 10);
	rkm.print_res("RUNGE KUTTA METHOD");

	AdamsBashfortMethod adams(0, 0, 70, 10);
	adams.print_res("ADAMS BASHFORT METHOD");

	adams.draw_res(argc, argv);

	return 0;
}