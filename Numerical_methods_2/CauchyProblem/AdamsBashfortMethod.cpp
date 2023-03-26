#include "AdamsBashfortMethod.h"
double* AdamsBashfortMethod::solution(double* x)
{

	if (count_of_nodes < 4) {
		throw "Not enough nodes";
	}

	double* res = new double[count_of_nodes + 1];
	res[0] = y0;
	res[1] = res[0] + h * f(x[0], res[0]);
	res[2] = res[1] + (h / 2) * (3 * f(x[1], res[1]) - f(x[0], res[0]));
	res[3] = res[2] + (h / 12) * (23 * f(x[2], res[2]) - 16 * f(x[1], res[1]) + 5 * f(x[0], res[0]));

	double k0 = res[0],
		k1 = res[1],
		k2 = res[2],
		k3 = res[3];

	for (int i = 4; i <= count_of_nodes; i++) {
		res[i] = k3 + (h / 24) * (55 * f(x[i - 1], k3) - 59 * f(x[i - 2], k2)
			   + 37 * f(x[i - 3], k1) - 9 * f(x[i - 4], k0));

		k0 = k1;
		k1 = k2;
		k2 = k3;
		k3 = res[i];
	}

	return res;
}

AdamsBashfortMethod::AdamsBashfortMethod(double _x0, double _y0, int count, double end) : CauchyProblem(_x0, _y0, count, end)
{
	counted_res = solution(x);
}
