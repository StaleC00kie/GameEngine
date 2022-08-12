#pragma once
#include <vector>
#include <iostream>
class Input
{
public:
	static Input* getInstance() { return m_instance; }

	bool isKeyDown(int inputKeyID);

	void handleEvents(int inputKeyID);

	void clearInputs();

protected:

	// give the Application class access to the Input singleton
	friend class Application;

	static Input* m_instance;

	static void create() { m_instance = new Input(); }
	static void destroy() { delete m_instance; }



	std::vector<int> m_pressedKeys;


private:

	// constructor private for singleton
	Input();
	~Input();
};

