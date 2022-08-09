#pragma once
#include "Application.h"
#include "Input.h"
#include <iostream>
class Application3D : public Application
{
public:

	bool startup() override;
	void shutdown() override;
	void update(float deltaTime) override;
	void draw() override;
};

