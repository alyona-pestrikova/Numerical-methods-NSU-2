#pragma once

#include "CauchyProblem.h"


//Eckb |f'(y)| <= L, то метод сходитс€
//ѕогрешность на шаге: O(h^4)

class RungeKuttaMethod: public CauchyProblem
{
private:
	double* solution(double* x);
public:
	RungeKuttaMethod(double _x0, double _y0, int count, double end);
};

