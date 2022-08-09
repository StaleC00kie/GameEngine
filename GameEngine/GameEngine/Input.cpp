#include "Input.h"

Input* Input::m_instance = nullptr;

Input::Input()
{

}

Input::~Input()
{
}

bool Input::isKeyDown(int inputKeyID)
{
	if (std::count(m_pressedKeys.begin(), m_pressedKeys.end(), inputKeyID))
	{
		return true;
	}

	return false;
}

void Input::handleEvents(int inputKeyID)
{
	m_pressedKeys.push_back(inputKeyID);

	if (m_pressedKeys.size() > 0)
	{
		for (int i = 0; i < m_pressedKeys.size(); i++)
		{
			std::cout << m_pressedKeys[i] << std::endl;
		}
	}
}

void Input::clearInputs()
{
	m_pressedKeys.clear();
}
