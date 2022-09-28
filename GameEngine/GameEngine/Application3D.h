#pragma once
#include "Application.h"
#include <iostream>

class Input;

class Application3D : public Application
{
public:

	bool startup() override;
	void shutdown() override;
	void update(float deltaTime) override;
	void draw() override;
	void processInput(GLFWwindow* window) override;

protected:

};

