#include "Application.h"

Application::Application()
{
	m_fps = 0;
	m_windowShouldClose = false;
	m_window = nullptr;
}

Application::~Application() 
{

}

void Application::run(const char* title, int width, int height, bool fullscreen)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	if (createWindow(title, width, height, fullscreen) && startup())
	{
		// variables for timing
		double prevTime = glfwGetTime();
		double currTime = 0;
		double deltaTime = 0;
		unsigned int frames = 0;
		double fpsInterval = 0;

		while (!glfwWindowShouldClose(m_window))
		{
			// update delta time
			currTime = glfwGetTime();
			deltaTime = currTime - prevTime;
			if (deltaTime > 0.1f)
			{
				deltaTime = 0.1f;
			}

			prevTime = currTime;

			glfwPollEvents();

			// skip if minimised
			if (glfwGetWindowAttrib(m_window, GLFW_ICONIFIED) != 0)
			{
				continue;
			}

			// update fps every second
			frames++;
			fpsInterval += deltaTime;
			if (fpsInterval >= 1.0f) {
				m_fps = frames;
				frames = 0;
				fpsInterval -= 1.0f;
			}

			update((float)deltaTime);


			glfwSwapBuffers(m_window);
		}
	}

	glfwTerminate();
	std::cout << "Closing" << std::endl;
	return;
}

bool Application::createWindow(const char* title, int width, int height, bool fullscreen)
{
	m_window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	glViewport(0, 0, 800, 600);

	return true;
}

void Application::frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
