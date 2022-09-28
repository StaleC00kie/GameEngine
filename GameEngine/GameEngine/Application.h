#pragma once
#include <iostream>
#include <glad/glad.h> 
#include "GLFW/glfw3.h"
#include "Input.h"
#include "Shader.h"
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

	virtual void processInput(GLFWwindow* window) = 0;

	void frameBufferSizeCallback(GLFWwindow* window, int width, int height);


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

	GLFWwindow* m_window;
	Input* m_input;
	Shader* m_shader;
};

