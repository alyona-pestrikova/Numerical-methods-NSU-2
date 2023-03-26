#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <GL/glew.h>
#include <gl/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

static struct Dot {
	float x;
	float y;
	Dot(float _x, float _y): x(_x), y(_y) {}
};

static std::vector<std::function<float(float)>> functions; //функции
static std::vector<std::vector<Dot>> dots; //точки для построения линий

const float step = 0.01;
const float scale = 20;

class Graphic
{
private:
	
	int argc;
	char** argv;
	static const int COUNT = 81; //количество клеток в столбце таблицы
	//static float step;          //шаг при построении функций

	static const char* readFile(const char* filepath); //считывание данных из файла шейдера
	static bool compiledStatus(GLint shaderID);  
	static GLuint makeVertexShader(const char* shaderSource);
	static GLuint makeFragmentShader(const char* shaderSource);
	static GLuint makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID);
	static void changeViewport(int w, int h);
	static void grid_draw(int& num_ind);
	static void coord_draw(int& num_ind);
	static void functions_draw(int& num_ind, std::function<float(float)> fun);
	static void dots_draw(int& num_ind, std::vector<Dot> _dots);
	static void render();

public:

	Graphic(int _argc, char** _argv);
	void draw_graphic();
	void add_function(std::function<double(double)>);
	void add_dots_array(std::vector<Dot> dots);
};