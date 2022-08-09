#pragma once
#include "SDL2/SDL.h"
#include <iostream>
#include "Input.h"
class Application
{
public:

	Application();
	virtual ~Application();

	// creates a window and begins the game loop which calls update() and draw() repeatedly
	// it first calls startup() and if that succeeds it then starts the loop,
	// ending with shutdown().
	void run(const char* title, int width, int height, bool fullscreen);

	virtual bool startup() = 0;
	virtual void shutdown() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;

	//void clearScreen();

	//void setVSync(bool enabled);

	//unsigned int getFPS() const { return m_fps; }

	//// returns time since application started
	//float getTime() const;

	//unsigned int getWindowWidth() const;
	//unsigned int getWindowHeight() const;

protected:

	virtual bool createWindow(const char* title, int width, int height, bool fullscreen);
	//virtual void destroyWindow();

	// if set to false, the main game loop will exit
	bool m_windowShouldClose;

	unsigned int m_fps;

	SDL_Window* window;
	SDL_Surface* screenSurface;
	SDL_Renderer* renderer;
};

