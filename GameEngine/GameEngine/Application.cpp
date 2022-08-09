#include "Application.h"

Application::Application()
{
	m_fps = 0;
	window = nullptr;
	renderer = nullptr;
	screenSurface = nullptr;
	m_windowShouldClose = false;
}

Application::~Application() 
{
	delete window;
	delete renderer;
}

void Application::run(const char* title, int width, int height, bool fullscreen)
{
	if (createWindow(title, width, height, fullscreen) && startup())
	{
		Input* input = Input::getInstance();
		while (!m_windowShouldClose)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event)) 
			{
				if (event.type == SDL_KEYDOWN)
				{
					input->handleEvents(event.key.keysym.sym);
				}
			}


			// variables for timing
			double prevTime = SDL_GetTicks64();
			double currTime = 0;
			double deltaTime = 0;
			unsigned int frames = 0;
			double fpsInterval = 0;


			// update delta time
			currTime = SDL_GetTicks64();
			deltaTime = currTime - prevTime;
			if (deltaTime > 0.1f)
			{
				deltaTime = 0.1f;
			}

			update((float)deltaTime);

			draw();
		}

		SDL_Quit();
	}
}

bool Application::createWindow(const char* title, int width, int height, bool fullscreen)
{
	int windowFlags = 0;
	int rendererFlags = SDL_RENDERER_ACCELERATED;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Could not initalize SDL." << std::endl;
		return false;
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, windowFlags);

	// Did creating the window fail?
	if (!window)
	{
		std::cout << "Failed to create/open SDL window." << std::endl;
		return false;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
	renderer = SDL_CreateRenderer(window, -1, rendererFlags);

	// Did creating the renderer fail?
	if (!renderer)
	{
		std::cout << "Failed to create SDL renderer." << std::endl;
		return false;
	}

	screenSurface = SDL_GetWindowSurface(window);

	Input::create();

	return true;
}