#include "Text.h"

//==========================================================================
// Text cosntructor
//==========================================================================
Mach::Text::Text()
{
}

//==========================================================================
// Text constructor
//==========================================================================
Mach::Text::Text(int x, int y, std::string text, Mach::Font* font, int fontSize, Mach::Color color)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Color = color;
	m_Font = font;
	m_FontSize = fontSize;
	m_String = text;

	// Initialize sf::Text
	update();
}

//==========================================================================
// Text constructor
//==========================================================================
Mach::Text::Text(int x, int y, const char* text, Mach::Font* font, int fontSize, Mach::Color color)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Color = color;
	m_Font = font;
	m_FontSize = fontSize;
	m_String = text;

	// Initialize sf::Text
	update();
}

//==========================================================================
// Set the position of the text
//==========================================================================
void Mach::Text::setPosition(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
}

//==========================================================================
// Set the position of the text
//==========================================================================
void Mach::Text::setPosition(Vector2i position)
{
	m_Position = position;
}

//==========================================================================
// Set the color of the text
//==========================================================================
void Mach::Text::setFont(Mach::Font* font)
{
	m_Font = font;
	update();
}

//==========================================================================
// Set the color of the text
//==========================================================================
void Mach::Text::setColor(Mach::Color color)
{
	m_Color = color;
}

//==========================================================================
// Draw the text to the window
//==========================================================================
void Mach::Text::draw(Mach::Window* window)
{
	LOG_WARN << "Drawing has not yet been implemented";
}

//==========================================================================
// Update the underlying sf::Text object
//==========================================================================
void Mach::Text::update()
{
	m_TextObject.setCharacterSize(m_FontSize);
	m_TextObject.setFillColor(sf::Color(m_Color.r, m_Color.g, m_Color.b, m_Color.a));
	m_TextObject.setFont(*m_Font->get());
	m_TextObject.setPosition(m_Position.x, m_Position.y);
	m_TextObject.setStyle(sf::Text::Style::Regular);
	m_TextObject.setString(m_String);
}
