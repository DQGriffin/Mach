#include "Circle.h"

//==========================================================================
// Circle constructor
//==========================================================================
Mach::Circle::Circle()
{
	m_OutlineColor = Color::Transparent;
	m_FillColor = Color::Transparent;
	m_Radius = 1.0f;
	m_OutlineThickness = 0;	
}

//==========================================================================
// Circle copy constructor
//==========================================================================
Mach::Circle::Circle(const Circle& other)
{
	setPosition(other.getPosition());
	setOrigin(other.getOrigin());
	setRotation(other.getRotation());
	setScale(other.getScale());
	m_FillColor = other.m_FillColor;
	m_OutlineColor = other.m_OutlineColor;
	m_Radius = other.m_Radius;
	m_OutlineThickness = other.m_OutlineThickness;	
}

//==========================================================================
// Circle copy assignment
//==========================================================================
void Mach::Circle::operator=(const Circle& other)
{
	setPosition(other.getPosition());
	setOrigin(other.getOrigin());
	setRotation(other.getRotation());
	setScale(other.getScale());
	m_FillColor = other.m_FillColor;
	m_OutlineColor = other.m_OutlineColor;
	m_Radius = other.m_Radius;
	m_OutlineThickness = other.m_OutlineThickness;
}

//==========================================================================
// Set the fill color of the circle
//==========================================================================
void Mach::Circle::setFillColor(Mach::Color color)
{
	m_FillColor = color;
}

//==========================================================================
// Set the outline color of the color
//==========================================================================
void Mach::Circle::setOutlineColor(Mach::Color color)
{
	m_OutlineColor = color;
}

//==========================================================================
// Set the radius the color
//==========================================================================
void Mach::Circle::setRadius(int radius)
{
	m_Radius = radius;
}

//==========================================================================
// Set the outline thickness of the circle
//==========================================================================
void Mach::Circle::setOutlineThickness(int outlineThickness)
{
	m_OutlineThickness = outlineThickness;
}

//==========================================================================
// Get the fill color of the Circle
//==========================================================================
Mach::Color Mach::Circle::getFillColor()
{
	return m_FillColor;
}

//==========================================================================
// Get the fill coloe of the Circle
//==========================================================================
Mach::Color Mach::Circle::getFillColor() const
{
	return m_FillColor;
}

//==========================================================================
// Get the outline color of the Circle
//==========================================================================
Mach::Color Mach::Circle::getOutlineColor()
{
	return Mach::Color();
}

//==========================================================================
// Get the outline color of the Circle
//==========================================================================
Mach::Color Mach::Circle::getOutlineColor() const
{
	return Mach::Color();
}

//==========================================================================
// Get the radius of the circle
//==========================================================================
int Mach::Circle::getRadius()
{
	return m_Radius;
}

//==========================================================================
// Get the radius of the circle
//==========================================================================
int Mach::Circle::getRadius() const
{
	return m_Radius;
}

//==========================================================================
// Get the outline thickness of the circle
//==========================================================================
int Mach::Circle::getOutlineThickness()
{
	return m_OutlineThickness;
}

//==========================================================================
// Get the outline thickness of the circle
//==========================================================================
int Mach::Circle::getOutlineThickness() const
{
	return m_OutlineThickness;
}

//==========================================================================
// Draw the circle to the window
//==========================================================================
void Mach::Circle::draw(sf::RenderWindow* window)
{
	update();
	window->draw(m_Circle);
}

//==========================================================================
// Update the underlying sf::CircleShape
//==========================================================================
void Mach::Circle::update()
{
	m_Circle.setRadius(m_Radius);
	m_Circle.setFillColor(sf::Color(m_FillColor.r, m_FillColor.g, m_FillColor.b, m_FillColor.a));
	m_Circle.setPosition(sf::Vector2f(getPosition().x, getPosition().y));
	m_Circle.setOutlineColor(sf::Color(m_OutlineColor.r, m_OutlineColor.g, m_OutlineColor.b, m_OutlineColor.a));
	m_Circle.setOutlineThickness(m_OutlineThickness);
}
