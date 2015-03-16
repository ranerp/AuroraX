#define GLFW_INCLUDE_GLU

#pragma once

#include "GL/glew.h"
#define GLFW_DLL
#include "GLFW/glfw3.h"
#include <iostream>

#include "IO/FileIO.h"

using namespace std;

static bool isFullScreen = false;
static GLFWmonitor* monitor = NULL;

static void CloseCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

static void ErrorCallback(int error, const char* description)
{
	fputs(description, stderr);
}

static void Terminate(int _CODE)
{
	glfwTerminate();
	exit(_CODE);
}

int main(void)
{
	if (!glfwInit())
	{
		Terminate(EXIT_FAILURE);
	}

	int Major, Minor, Rev;

	glfwGetVersion(&Major, &Minor, &Rev);

	cout << "GLFW " << Major << " " << Minor << " " << Rev << " initialized" << endl;

	glfwSetErrorCallback(ErrorCallback);

	GLFWmonitor* monitor = isFullScreen ? glfwGetPrimaryMonitor() : NULL;

	GLFWwindow* window = glfwCreateWindow(800, 600, "AuroraX", monitor, NULL);

	if (!window)
	{
		Terminate(EXIT_FAILURE);
	}

	glfwSetKeyCallback(window, CloseCallback);

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	
	if (glewInit() != GLEW_OK)
	{
		Terminate(EXIT_FAILURE);
	}

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	cout << "Renderer version: " << renderer << endl;
	cout << "OpenGL version supported: " << version << endl;

	while (!glfwWindowShouldClose(window))
	{

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwDestroyWindow(window);

	Terminate(EXIT_SUCCESS);

	return 0;
}