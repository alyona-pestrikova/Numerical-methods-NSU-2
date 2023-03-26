#pragma once
#include "CauchyProblem.h"

//����������� �� ����: O(h^5)

class AdamsBashfortMethod: public CauchyProblem
{
private:
	double* solution(double* x);
public:
	AdamsBashfortMethod(double _x0, double _y0, int count, double end);
};

