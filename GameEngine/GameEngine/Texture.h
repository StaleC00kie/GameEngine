#pragma once
class Texture
{
public:
	Texture();
	~Texture();

protected:
	int m_width, m_height, m_nrChannels;
	unsigned char* m_data;
};

