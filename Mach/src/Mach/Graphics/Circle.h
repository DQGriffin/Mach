#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "..//MachAPI.h"
#include "Transformable.h"
#include "Drawable.h"
#include "Color.h"

namespace Mach
{
	class MACH_API Circle : public Drawable, Transformable
	{
	public:
	private:
		sf::CircleShape m_Circle;
		Color m_OutlineColor;
		Color m_FillColor;
		int m_Radius;
		int m_OutlineThickness;
	public:
		Circle();
		Circle(const Circle& other);
		void operator=(const Circle& other);
		void setFillColor(Mach::Color color);
		void setOutlineColor(Mach::Color color);
		void setRadius(int radius);
		void setOutlineThickness(int outlineThickness);
		Mach::Color getFillColor();
		Mach::Color getFillColor() const;
		Mach::Color getOutlineColor();
		Mach::Color getOutlineColor() const;
		int getRadius();
		int getRadius() const;
		int getOutlineThickness();
		int getOutlineThickness() const;
		void draw(sf::RenderWindow* window) override;
	private:
		void update();
	};
}