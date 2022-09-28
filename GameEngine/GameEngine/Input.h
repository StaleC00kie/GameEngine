#pragma once
#include <vector>
#include <iostream>
#include "GLFW/glfw3.h"
#include <algorithm>
class Input
{
public:

	Input(GLFWwindow* window);
	~Input();

	bool isKeyDown(int key);
	bool isKeyHeldDown(int inputKeyID);

	void clearInputs();

	static void callback(GLFWwindow* window, int key, int scancode, int action, int mods);

protected:

	static std::vector<int> m_pressedKeys;

	GLFWwindow* m_window;
};

