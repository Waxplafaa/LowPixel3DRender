#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>

std::vector<float> add3(const std::vector<float>& a , const std::vector<float>& b ) {	//加
	std::vector<float> c(3);
	c[0] = a[0] + b[0];
	c[1] = a[1] + b[1];
	c[2] = a[2] + b[2];
	return c;
}

std::vector<float> sub3(const std::vector<float>& a, const std::vector<float>& b) {		//减

	std::vector<float> c(3);
	c[0] = a[0] - b[0];
	c[1] = a[1] - b[1];
	c[2] = a[2] - b[2];
	return c;
}

float pop3(const std::vector<float>& a, const std::vector<float>& b) {                  //点乘
	float c = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	return c;
}

std::vector<float> crp3(const std::vector<float>& a, const std::vector<float>& b) {     //叉乘
	std::vector<float> c(3);
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
	return c;
}

std::vector<float> scl3(const std::vector<float>& a, float b) {							//数乘
	std::vector<float> c(3);
	c[0] = a[0] * b;
	c[1] = a[1] * b;
	c[2] = a[2] * b;
	return c;
}

//初始变量
float campos[3] = { 0,0,0 };
float scrpos[3] = { 1,1,1 };
float scrscl = 1;
int scrlth = 40;
int scrwth = 30;
bool up = false;
bool down = false;
bool forw = false;
bool back = false;
bool left = false;
bool right = false;

void keycb(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_W) {
		if (action == GLFW_PRESS) forw = true;
		if (action == GLFW_RELEASE) forw = false;
	}
	if (key == GLFW_KEY_S) {
		if (action == GLFW_PRESS) back = true;
		if (action == GLFW_RELEASE) back = false;
	}
	if (key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) left = true;
		if (action == GLFW_RELEASE) left = false;
	}
	if (key == GLFW_KEY_D) {
		if (action == GLFW_PRESS) right = true;
		if (action == GLFW_RELEASE) right = false;
	}
	if (key == GLFW_KEY_R) {
		if (action == GLFW_PRESS) up = true;
		if (action == GLFW_RELEASE) up = false;
	}
	if (key == GLFW_KEY_F) {
		if (action == GLFW_PRESS) down = true;
		if (action == GLFW_RELEASE) down = false;
	}
}

int main() {
	//初始OpenGL
	if (!glfwInit()) return -1;
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);	//配置OpenGL

	//创建窗口
	GLFWwindow* window = glfwCreateWindow(800, 600, "Graphic3D", nullptr, nullptr);
	if (!window) {
		std::cout << "[err]:无法创建窗口" << std::endl;
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	//初始glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "[err]:GLAD无法初始化" << std::endl;
		return -1;
	}

	//因为还不会读外部文件，所以先直接在代码里面写模型
	//模型
	std::vector<float> surf1point = { 0,0,0, 1,0,0, 0,0,1 };
	std::vector<int> surf1scale = { 1,1 };
	std::vector<float> surf1color = { 1,0,0 };
	std::vector<float> surf2point = { 0,0,0, 1,0,0, 0,1,0 };
	std::vector<int> surf2scale = { 1,1 };
	std::vector<float> surf2color = { 0,1,0 };
	std::vector<float> surf3point = { 0,0,0, 0,1,0, 0,0,1 };
	std::vector<int> surf3scale = { 1,1 };
	std::vector<float> surf3color = { 0,0,1 };


	//渲染
	while (!glfwWindowShouldClose(window)) {

		glClear(GL_COLOR_BUFFER_BIT);    //刷新

		glfwSwapBuffers(window);
		glfwPollEvents();
		
	}
}