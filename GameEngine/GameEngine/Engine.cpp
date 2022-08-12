#include "Engine.h"

Engine::Engine()
{

}

Engine::~Engine()
{
}

bool Engine::startup()
{

	return true;
}

void Engine::shutdown()
{

}

void Engine::update(float deltaTime)
{
	if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(m_window, true);
	}
}

void Engine::draw()
{

}
