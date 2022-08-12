#pragma once

#include "Application3D.h"
#include <GLFW/glfw3.h>

class Engine : public Application
{
public:

	Engine();
	~Engine();

	bool startup() override;
	void shutdown() override;
	void update(float deltaTime) override;
	void draw() override;

};

