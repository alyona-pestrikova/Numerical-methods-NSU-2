#pragma once

#include "CauchyProblem.h"

//����� ������� �� ������������� ������������ ������

//����������� �� ����: O(h^2)

class EulerMethod: public CauchyProblem
{
private:
	double* solution(double* x) override;
public:
	EulerMethod(double _x0, double _y0, int count, double end);
};

