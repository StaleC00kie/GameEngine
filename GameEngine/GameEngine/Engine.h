#pragma once
#include "Application3D.h"

class Engine : public Application3D
{
public:

	Engine();
	virtual ~Engine();

	bool startup() override;
	void shutdown() override;
	void update(float deltaTime) override;
	void draw() override;

};

