#include "Sprite.h"

//==========================================================================
// Sprite constructor
//==========================================================================
Mach::Sprite::Sprite()
{
	m_Texture = nullptr;
	m_Position.x = 0;
	m_Position.y = 0;
}

//==========================================================================
// Sprite constructor
//==========================================================================
Mach::Sprite::Sprite(Mach::Texture& texture)
{
	m_Texture = &texture;
	m_Position.x = 0;
	m_Position.y = 0;
	update();
}

//==========================================================================
// Sprite constructor
//==========================================================================
Mach::Sprite::Sprite(const Sprite& other)
{
	m_Texture = other.m_Texture;
	m_Position = other.m_Position;
	m_Sprite = other.m_Sprite;
	update();
}

void Mach::Sprite::update()
{
	m_Sprite.setPosition(sf::Vector2f(m_Position.x, m_Position.y));
	m_Sprite.setTexture(*m_Texture->get());
}

//==========================================================================
// Draw the sprite
//==========================================================================
void Mach::Sprite::draw(sf::RenderWindow* window)
{
	window->draw(m_Sprite);
}
