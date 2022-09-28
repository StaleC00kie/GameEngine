#pragma once

#include "Application.h"
#include "stb/stb_image.h"


class Engine : public Application
{
public:

	Engine();
	~Engine();

	bool startup() override;
	void shutdown() override;
	void update(float deltaTime) override;
	void draw() override;
	void processInput(GLFWwindow* window) override;

protected:

	float m_vertices[18] = {
		// positions         // colors
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
	};

	unsigned int m_indices[6] = {  // note that we start from 0!
	0, 1, 3,  // first Triangle
	1, 2, 3   // second Triangle
	};

	unsigned int shaderProgram;

	unsigned int VBO, VAO, EBO;
};

