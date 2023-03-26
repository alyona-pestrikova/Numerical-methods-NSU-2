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
	double h;                     //��� �����
	double* x;                    //��������� �������
	int count_of_nodes;
	double* precise_res;          //������ �������� � ������ ���������
	double* counted_res;          //����������� ��������� � ������ ���������
	double f(double x, double y); //y' = f(x, y)
	static double precise_sol(double); //������ �������
	virtual double* solution(double* x) = 0; 
	double inaccuracy(double counted, double precise); //������������� �����������
public:
	CauchyProblem(double _x0, double _y0, int count, double end);
	~CauchyProblem();
	void print_res(std::string name = ""); //����� ���������� � ����������
	void draw_res(int _argc, char** _argv); //���������� �������
};

