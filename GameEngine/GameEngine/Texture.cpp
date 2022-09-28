#include "Texture.h"

Texture::Texture()
{
	m_width = 0;
	m_height = 0;
	m_nrChannels = 0;
	m_data = 0;
	
}

Texture::~Texture()
{
	delete m_data;
}