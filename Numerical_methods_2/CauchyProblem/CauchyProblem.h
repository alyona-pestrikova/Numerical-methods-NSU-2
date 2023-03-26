#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <algorithm>
#include "../Graphic/graphic.h"

class CauchyProblem
{
protected:
	double x0, y0;                //y(x0) = y0
	double h;                     //шаг сетки
	double* x;                    //разбиение отрезка
	int count_of_nodes;
	double* precise_res;          //точный резульат в точках разбиения
	double* counted_res;          //вычисленный результат в точках разбиения
	double f(double x, double y); //y' = f(x, y)
	static double precise_sol(double); //точное решение
	virtual double* solution(double* x) = 0; 
	double inaccuracy(double counted, double precise); //относительная погрешность
public:
	CauchyProblem(double _x0, double _y0, int count, double end);
	~CauchyProblem();
	void print_res(std::string name = ""); //вывод результата и статистики
	void draw_res(int _argc, char** _argv); //построение графика
};

