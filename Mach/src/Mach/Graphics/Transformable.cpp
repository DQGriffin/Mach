#include "Transformable.h"

//==========================================================================
// Transformable constructor
//==========================================================================
Mach::Transformable::Transformable()
{
	m_Position = { 0, 0 };
	m_Scale = { 1, 1 };
	m_Origin = { 0, 0 };
	m_Rotation = 1.0f;
}

//==========================================================================
// Set the position of the Transformable
//==========================================================================
void Mach::Transformable::setPosition(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
}

//==========================================================================
// Set the position of the Transformable
//==========================================================================
void Mach::Transformable::setPosition(Vector2i position)
{
	m_Position = position;
}

//==========================================================================
// Set the origin of the Transformable
//==========================================================================
void Mach::Transformable::setOrigin(int x, int y)
{
	m_Origin.x = x;
	m_Origin.y = y;
}

//==========================================================================
// Set the origin of the Transformable
//==========================================================================
void Mach::Transformable::setOrigin(Vector2i origin)
{
	m_Origin = origin;
}

//==========================================================================
// Set the rotation of the Transformable
//==========================================================================
void Mach::Transformable::setRotation(float rotation)
{
	m_Rotation = rotation;
}

//==========================================================================
// Set the scale of the transformable
//==========================================================================
void Mach::Transformable::setScale(int x, int y)
{
	m_Scale.x = x;
	m_Scale.y = y;
}

//==========================================================================
// Set the scale of the Transformable
//==========================================================================
void Mach::Transformable::setScale(Vector2i scale)
{
	m_Scale = scale;
}

//==========================================================================
// Get the position of the Transformable
//==========================================================================
Mach::Vector2i Mach::Transformable::getPosition()
{
	return m_Position;
}

//==========================================================================
// Get the position of the Transformable
//==========================================================================
Mach::Vector2i Mach::Transformable::getPosition() const
{
	return m_Position;
}

//==========================================================================
// Get the origin of the Transformable
//==========================================================================
Mach::Vector2i Mach::Transformable::getOrigin()
{
	return m_Origin;
}

//==========================================================================
// Get the origin of the Transformable
//==========================================================================
Mach::Vector2i Mach::Transformable::getOrigin() const
{
	return m_Origin;
}

//==========================================================================
// Get the scale of the Transformable
//==========================================================================
Mach::Vector2i Mach::Transformable::getScale()
{
	return m_Scale;
}

//==========================================================================
// Get the scale of the Transformable
//==========================================================================
Mach::Vector2i Mach::Transformable::getScale() const
{
	return m_Scale;
}

//==========================================================================
// Get the rotation of the Transformable
//==========================================================================
float Mach::Transformable::getRotation()
{
	return m_Rotation;
}

//==========================================================================
// Get the rotation of the Transformable
//==========================================================================
float Mach::Transformable::getRotation() const
{
	return m_Rotation;
}
