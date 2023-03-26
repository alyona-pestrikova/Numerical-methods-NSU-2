#include "RungeKuttaMethod.h"


double* RungeKuttaMethod::solution(double* x)
{
	double* res = new double[count_of_nodes + 1];

	res[0] = y0;

	double k1, k2, k3, k4;

	for (int i = 1; i <= count_of_nodes; i++) {

		k1 = f(x[i - 1], res[i - 1]);
		k2 = f(x[i - 1] + h / 2, res[i - 1] + k1 * h / 2);
		k3 = f(x[i - 1] + h / 2, res[i - 1] + k2 * h / 2);
		k4 = f(x[i - 1] + h, res[i - 1] + k3 * h);

		res[i] = res[i - 1] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
	}

	return res;
}

RungeKuttaMethod::RungeKuttaMethod(double _x0, double _y0, int count, double end) : CauchyProblem(_x0, _y0, count, end)
{
	counted_res = solution(x);
}