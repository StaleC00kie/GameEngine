#include "Input.h"


std::vector<int> Input::m_pressedKeys;

Input::Input(GLFWwindow* window)
{
	m_window = window;

	glfwSetKeyCallback(window, callback);
}

Input::~Input()
{
	delete m_window;
}

bool Input::isKeyDown(int key)
{
	auto it = std::find(m_pressedKeys.begin(), m_pressedKeys.end(), key);

	if (it != m_pressedKeys.end())
	{
		return true;
	}

	return false;
}

bool Input::isKeyHeldDown(int inputKeyID)
{
	return false;
}

void Input::clearInputs()
{

}

void Input::callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	auto it = std::find(m_pressedKeys.begin(), m_pressedKeys.end(), key);

	if (action == GLFW_PRESS && it == m_pressedKeys.end())
	{
		m_pressedKeys.push_back(key);
	}
	else if (action == GLFW_RELEASE && it != m_pressedKeys.end())
	{
		m_pressedKeys.erase(it, m_pressedKeys.end());
	}
}
