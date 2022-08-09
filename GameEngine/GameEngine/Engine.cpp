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
	Input* input = Input::getInstance();
	if (input->isKeyDown(SDLK_ESCAPE))
	{
		m_windowShouldClose = true;
	}

	input->clearInputs();
}

void Engine::draw()
{
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 75, 100, 1));

	SDL_UpdateWindowSurface(window);
}
