#include "Color.h"

const Mach::Color Mach::Color::WHITE{ 255, 255, 255 };
const Mach::Color Mach::Color::BLACK{ 0, 0, 0 };
const Mach::Color Mach::Color::RED{255, 0, 0};
const Mach::Color Mach::Color::GREEN{ 0, 255, 0 };
const Mach::Color Mach::Color::BLUE{ 0, 0, 255 };
const Mach::Color Mach::Color::YELLOW{ 255, 255, 0 };
const Mach::Color Mach::Color::ORANGE{ 255, 128, 0 };
const Mach::Color Mach::Color::MAGENTA{ 255, 0, 255 };

Mach::Color::Color()
{
	this->r = 255;
	this->g = 255;
	this->b = 255;
	this->a = 255;
}

Mach::Color::Color(int r, int g, int b, int a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}