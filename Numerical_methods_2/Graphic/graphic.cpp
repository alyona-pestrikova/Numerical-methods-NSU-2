#include "graphic.h"

Graphic::Graphic(int _argc, char** _argv): argc(_argc), argv(_argv) {}

void Graphic::draw_graphic()
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(1000, 800);
	glutCreateWindow("Graphic");
	glutReshapeFunc(changeViewport);
	glutDisplayFunc(render);
	glewInit();
	glutMainLoop();
}

void Graphic::add_function(std::function<double(double)> fun)
{
	functions.push_back(fun);
}

void Graphic::add_dots_array(std::vector<Dot> _dots)
{
	dots.push_back(_dots);
}

//считывание данных из файла шейдера
const char* Graphic::readFile(const char* filepath)
{
	FILE* fp = fopen(filepath, "r");
	fseek(fp, 0, SEEK_END);
	long file_length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char* contents = new char[file_length + 1];
	for (int i = 0; i < file_length + 1; i++) {
		contents[i] = 0;
	}
	fread(contents, 1, file_length, fp);
	contents[file_length + 1] = '\0';
	fclose(fp);
	return contents;
}

bool Graphic::compiledStatus(GLint shaderID)
{
	GLint compiled = 0;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compiled);
	if (compiled) {
		return true;
	}
	else {
		GLint logLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
		char* msgBuffer = new char[logLength];
		glGetShaderInfoLog(shaderID, logLength, NULL, msgBuffer);
		printf("%s\n", msgBuffer);
		delete[] msgBuffer;
		return false;
	}
}

GLuint Graphic::makeVertexShader(const char* shaderSource)
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, (const GLchar**)&shaderSource, NULL);
	glCompileShader(vertexShaderID);
	bool compiledCorrectly = compiledStatus(vertexShaderID);
	if (compiledCorrectly) {
		return vertexShaderID;
	}
	return -1;
}

GLuint Graphic::makeFragmentShader(const char* shaderSource)
{
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, (const GLchar**)&shaderSource, NULL);
	glCompileShader(fragmentShaderID);
	bool compiledCorrectly = compiledStatus(fragmentShaderID);
	if (compiledCorrectly) {
		return fragmentShaderID;
	}
	return -1;
}

GLuint Graphic::makeShaderProgram(GLuint vertexShaderID, GLuint fragmentShaderID)
{
	GLuint shaderID = glCreateProgram();
	glAttachShader(shaderID, vertexShaderID);
	glAttachShader(shaderID, fragmentShaderID);
	glLinkProgram(shaderID);
	return shaderID;
}

void Graphic::changeViewport(int w, int h)
{
	glViewport(0, 0, w, h);
}

void Graphic::grid_draw(int& num_ind)
{
	float w_width = glutGet(GLUT_WINDOW_WIDTH);
	float w_height = glutGet(GLUT_WINDOW_HEIGHT);
	int num_vertices = 2 * COUNT * (1.0f + w_width / w_height);
	num_vertices += num_vertices % 2;
	int num_indices = 3 * num_vertices;
	num_ind = num_indices;
	GLuint shader_program_id;
	GLuint vao = 0;
	GLuint vbo;
	GLuint position_id, color_id;
	GLuint index_buffer_id;

	GLfloat* vertices = new GLfloat[num_vertices * 3];


	for (int i = 0; i < 6 * COUNT; i += 3)
	{
		if (i > 6 * COUNT - 3) {
			throw "too much";
		}
		vertices[i] = pow(-1, i + 1);
		vertices[i + 1] = 1.0f - 2.0f * ((i / 3) / 2) * (1.0f / (COUNT - 1));
		vertices[i + 2] = 0.0f;
	}

	for (int i = 6 * COUNT; i < 3 * num_vertices; i += 3) {
		if (i > 3 * num_vertices - 3) {
			throw "too much";
		}
		vertices[i] = 1.0f - 2.0f * (((i - 6 * COUNT) / 3) / 2) * (1.0f / (COUNT * (w_width / w_height) - 1));
		vertices[i + 1] = pow(-1, i);
		vertices[i + 2] = 0.0f;

	}


	GLuint* indices = new GLuint[num_indices];


	for (int i = 0; i < num_indices; i++)
	{
		indices[i] = i;
	}

	const char* vertexShaderSourceCode = readFile("Graphic/vertexShader.glsl");
	const char* fragmentShaderSourceCode = readFile("Graphic/fragmentShader.glsl");
	GLuint vertShaderID = makeVertexShader(vertexShaderSourceCode);
	GLuint fragShaderID = makeFragmentShader(fragmentShaderSourceCode);
	shader_program_id = makeShaderProgram(vertShaderID, fragShaderID);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * num_vertices * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 3 * num_vertices * sizeof(GLfloat), vertices);

	glGenBuffers(1, &index_buffer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_indices * sizeof(GLuint), indices, GL_STATIC_DRAW);

	position_id = glGetAttribLocation(shader_program_id, "s_vPosition");

	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glUseProgram(shader_program_id);
	glEnableVertexAttribArray(position_id);

	delete[] vertices;
	delete[] indices;
}

void Graphic::coord_draw(int& num_ind)
{
	float w_width = glutGet(GLUT_WINDOW_WIDTH);
	float w_height = glutGet(GLUT_WINDOW_HEIGHT);
	int num_vertices = 4;
	int num_indices = 12;
	num_ind = num_indices;

	GLuint shader_program_id;
	GLuint vao = 0;
	GLuint vbo;
	GLuint position_id;
	GLuint index_buffer_id;

	GLfloat* vertices = new GLfloat[num_vertices * 3];

	vertices[0] = -1;
	vertices[1] = 0;
	vertices[2] = 0;
	vertices[3] = 1;
	vertices[4] = 0;
	vertices[5] = 0;
	vertices[6] = 0;
	vertices[7] = 1;
	vertices[8] = 0;
	vertices[9] = 0;
	vertices[10] = -1;
	vertices[11] = 0;

	GLuint* indices = new GLuint[num_indices];


	for (int i = 0; i < num_indices; i++)
	{
		indices[i] = i;
	}

	const char* vertexShaderSourceCode = readFile("Graphic/vertexShader.glsl");
	const char* fragmentShaderSourceCode = readFile("Graphic/coordFragShader.glsl");
	GLuint vertShaderID = makeVertexShader(vertexShaderSourceCode);
	GLuint fragShaderID = makeFragmentShader(fragmentShaderSourceCode);
	shader_program_id = makeShaderProgram(vertShaderID, fragShaderID);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * num_vertices * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 3 * num_vertices * sizeof(GLfloat), vertices);

	glGenBuffers(1, &index_buffer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_indices * sizeof(GLuint), indices, GL_STATIC_DRAW);

	position_id = glGetAttribLocation(shader_program_id, "s_vPosition");

	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glUseProgram(shader_program_id);
	glEnableVertexAttribArray(position_id);

	delete[] vertices;
	delete[] indices;
}

void Graphic::functions_draw(int& num_ind, std::function<float(float)> fun)
{
	GLuint shader_program_id;
	GLuint vao = 1;
	GLuint vbo;
	GLuint position_id;
	GLuint index_buffer_id;

	int num_vertices = 2 / step + 3;
	num_ind = 3 * num_vertices - 3;
	GLfloat* vertices = new GLfloat[num_ind];
	GLuint* indices = new GLuint[num_ind];
	for (int i = 0; i < num_ind; i += 3) {
		vertices[i] = 1.0f - ((float)i / 3) * step;
		vertices[i + 1] = fun(vertices[i] * scale) / scale;
		vertices[i + 2] = 0;

	}

	for (int i = 0; i < num_ind; i++) {
		indices[i] = i;
	}

	const char* vertexShaderSourceCode = readFile("Graphic/vertexShader.glsl");
	const char* fragmentShaderSourceCode = readFile("Graphic/coordFragShader.glsl");
	GLuint vertShaderID = makeVertexShader(vertexShaderSourceCode);
	GLuint fragShaderID = makeFragmentShader(fragmentShaderSourceCode);
	shader_program_id = makeShaderProgram(vertShaderID, fragShaderID);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * num_vertices * sizeof(GLfloat), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, 3 * num_vertices * sizeof(GLfloat), vertices);

	glGenBuffers(1, &index_buffer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_ind * sizeof(GLuint), indices, GL_STATIC_DRAW);

	position_id = glGetAttribLocation(shader_program_id, "s_vPosition");

	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glUseProgram(shader_program_id);
	glEnableVertexAttribArray(position_id);

	delete[] vertices;
	delete[] indices;
}

void Graphic::dots_draw(int& num_ind, std::vector<Dot> _dots)
{
	GLuint shader_program_id;
	GLuint vao = 1;
	GLuint vbo;
	GLuint position_id;
	GLuint index_buffer_id;

	GLuint num_vertices = 2 * _dots.size() - 2; //6
	num_ind = 3 * num_vertices; //18

	GLfloat* vertices = new GLfloat[3 * num_vertices];


	int co = 0;
	for (int i = 0; i < 3 * num_vertices; i+=6) {
		vertices[i] = _dots[co].x / scale;
		vertices[i + 1] = _dots[co].y / scale;
		vertices[i + 2] = 0;
		co++;
		vertices[i + 3] = _dots[co].x / scale;
		vertices[i + 4] = _dots[co].y / scale;
		vertices[i + 5] = 0;
	}

	GLuint* indices = new GLuint[num_ind];
	for (int i = 0; i < num_ind; i++) {
		indices[i] = i;
	}
			


	const char* vertexShaderSourceCode = readFile("Graphic/vertexShader.glsl");
	const char* fragmentShaderSourceCode = readFile("Graphic/dotsFragmentShader.glsl");
	GLuint vertShaderID = makeVertexShader(vertexShaderSourceCode);
	GLuint fragShaderID = makeFragmentShader(fragmentShaderSourceCode);
	shader_program_id = makeShaderProgram(vertShaderID, fragShaderID);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 3 * num_vertices * sizeof(GLfloat), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &index_buffer_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * num_vertices * sizeof(GLuint), indices, GL_STATIC_DRAW);

	position_id = glGetAttribLocation(shader_program_id, "s_vPosition");

	glEnableVertexAttribArray(position_id);
	glVertexAttribPointer(position_id, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glUseProgram(shader_program_id);
	

	glDrawArrays(GL_LINES, 0, num_ind - 1);

	glDisableVertexAttribArray(position_id);


	delete[] vertices;
	delete[] indices;
}

void Graphic::render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.1f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	gluLookAt(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	int num_ind;
	grid_draw(num_ind);
	glDrawElements(GL_LINES, num_ind, GL_UNSIGNED_INT, NULL);
	coord_draw(num_ind);
	glDrawElements(GL_LINES, num_ind, GL_UNSIGNED_INT, NULL);

	for (int i = 0; i < functions.size(); i++) {
		functions_draw(num_ind, functions[i]);
		glDrawElements(GL_LINE_STRIP, num_ind, GL_UNSIGNED_INT, NULL);
	}

	for (int i = 0; i < dots.size(); i++) {
		dots_draw(num_ind, dots[i]);
		//glDrawElements(GL_LINE_STRIP, num_ind, GL_UNSIGNED_INT, NULL);
		//glDrawArrays(GL_LINE_STRIP, 0, num_ind);
	}
	
	glutSwapBuffers();
}
