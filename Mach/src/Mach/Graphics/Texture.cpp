#include "Texture.h"

//==========================================================================
// Texture constructor
//==========================================================================
Mach::Texture::Texture()
{
}

//==========================================================================
// Texture constructor
//==========================================================================
Mach::Texture::Texture(const std::string& path)
{
	loadFromFile(path);
}

//==========================================================================
// Texture copy constructor
//==========================================================================
Mach::Texture::Texture(const Texture& other)
{
	m_Texture = other.m_Texture;
}

//==========================================================================
// Copy assignment
//==========================================================================
void Mach::Texture::operator=(const Texture& other)
{
	m_Texture = other.m_Texture;
}

//==========================================================================
// Create an empty texture with the given size
//==========================================================================
bool Mach::Texture::create(unsigned int width, unsigned int height)
{
	return m_Texture.create(width, height);
}

//==========================================================================
// Load a texture from a file
//==========================================================================
bool Mach::Texture::loadFromFile(std::string path)
{
	return m_Texture.loadFromFile(path);
}

//==========================================================================
// Get the size of the texture
//==========================================================================
Mach::Vector2i Mach::Texture::getSize()
{
	return Mach::Vector2i(m_Texture.getSize().x, m_Texture.getSize().y);
}

//==========================================================================
// Get the underlying sf::Texture
//==========================================================================
sf::Texture* Mach::Texture::get()
{
	return &m_Texture;
}
