#include "Application3D.h"

bool Application3D::startup()
{
	return true;
}

void Application3D::shutdown()
{

}

void Application3D::update(float deltaTime)
{
	Input* input = Input::getInstance();

	if (input->isKeyDown(SDLK_ESCAPE))
	{
		std::cout << "Closing Window" << std::endl;
	}
}

void Application3D::draw()
{

}
