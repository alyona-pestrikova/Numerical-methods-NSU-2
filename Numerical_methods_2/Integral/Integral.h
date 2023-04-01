#pragma once

#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
struct pair {
	float res;
	int steps_count;
};

class Integral
{
private:
	std::function<float(float)> fun;
public:
	Integral(std::function<float(float)>);
	pair rectangle_method(float start, float end, float eps, char type = 'm');
	pair trapetion_method(float start, float end, float eps);
	pair simpson_method(float start, float end, float eps);
};

