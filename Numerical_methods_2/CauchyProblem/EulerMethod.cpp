#include "EulerMethod.h"

double* EulerMethod::solution(double* x)
{
	double* res = new double[count_of_nodes + 1];
	res[0] = y0;
	for (int i = 1; i <= count_of_nodes; i++) {
		res[i] = res[i - 1] + h * f(x[i - 1], res[i - 1]);
	}

	return res;
}

EulerMethod::EulerMethod(double _x0, double _y0, int count, double end) :CauchyProblem(_x0, _y0, count, end)
{
	counted_res = solution(x);
}
