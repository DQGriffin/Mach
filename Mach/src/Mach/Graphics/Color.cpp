#include "Color.h"

const Mach::Color Mach::Color::White{ 255, 255, 255 };
const Mach::Color Mach::Color::Black{ 0, 0, 0 };
const Mach::Color Mach::Color::Red{255, 0, 0};
const Mach::Color Mach::Color::Green{ 0, 255, 0 };
const Mach::Color Mach::Color::Blue{ 0, 0, 255 };
const Mach::Color Mach::Color::Yellow{ 255, 255, 0 };
const Mach::Color Mach::Color::Orange{ 255, 128, 0 };
const Mach::Color Mach::Color::Magenta{ 255, 0, 255 };
const Mach::Color Mach::Color::Transparent{255, 255, 255, 0};

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