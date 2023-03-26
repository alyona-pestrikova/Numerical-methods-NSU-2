#include "CauchyProblem.h"

double CauchyProblem::f(double x, double y)
{
	return -1 * y * cos(x) + exp(-1 * sin(x));
	//return 3 * pow(x, 2);
	//return exp(x * 2); //0, 0.5
}

double CauchyProblem::precise_sol(double x)
{
	return x * exp(-1 * sin(x));
	//return pow(x, 3);
	//return 0.5 * exp(x * 2);
}

double CauchyProblem::inaccuracy(double counted, double precise)
{
	if (precise == 0) {
		return counted;
	}
	return abs(counted - precise) / precise;
}

CauchyProblem::CauchyProblem(double _x0, double _y0, int count, double end)
{
	x0 = _x0;
	y0 = _y0;
	count_of_nodes = count;

	x = new double[count_of_nodes + 1];
	h = (end - x0) / count_of_nodes;
	for (int i = 0; i <= count_of_nodes; i++) {
		x[i] = x0 + i * h;
	}

	precise_res = new double[count_of_nodes + 1];

	for (int i = 0; i <= count_of_nodes; i++) {
		precise_res[i] = precise_sol(x[i]);
	}

}

CauchyProblem::~CauchyProblem()
{
	delete[] x;
	delete[] precise_res;
	delete[] counted_res;
}

void CauchyProblem::print_res(std::string name)
{
	if (name != "") {
		std::cout << name << std::endl;
	}
	std::cout << std::setw(6) << "X |";
	std::cout << std::setw(14) << " COUNTED RES |";
	std::cout << std::setw(15) << " PRECISE RES |";
	std::cout << std::setw(15) << " INACCURANCY";
	std::cout << std::endl;

	double max_inaccur = 0;

	for (int i = 0; i <= count_of_nodes; i++) {
		std::cout << std::setw(7) << x0 + i * h;
		std::cout << std::setw(14) << counted_res[i] << " ";
		std::cout << std::setw(14) << precise_res[i] << " ";
		double inaccur = inaccuracy(counted_res[i], precise_res[i]);
		if (inaccur > max_inaccur) {
			max_inaccur = inaccur;
		}
		std::cout << std::setw(14) << inaccur * 100 << "%";
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << "MAX INACCURACY = " << max_inaccur * 100 << "%" << std::endl << 
																						std::endl << std::endl;


}

void CauchyProblem::draw_res(int _argc, char** _argv)
{
	std::vector<Dot> dots;

	for (int i = 0; i <= count_of_nodes; i++) {
		dots.push_back({ (float) (x0 + i * h), (float)counted_res[i] });
	}

	Graphic graph(_argc, _argv);
	graph.add_function(CauchyProblem::precise_sol);
	graph.add_dots_array(dots);
	graph.draw_graphic();

}
