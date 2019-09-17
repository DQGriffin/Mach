////////////////////////////////////////////////////////////
//
// Mach Engine
// Copyright (C) 2019 D'Quavius J. Griffin
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from ny source distribution.
//
////////////////////////////////////////////////////////////

#pragma once
#include "..//MachAPI.h"
#include <iostream>
#include <algorithm>

namespace Mach
{
	class MACH_API Color
	{
	public:
		int r;
		int g;
		int b;
		int a;

		static const Color WHITE;
		static const Color BLACK;
		static const Color RED;
		static const Color GREEN;
		static const Color BLUE;
		static const Color YELLOW;		
		static const Color ORANGE;
		static const Color MAGENTA;
	private:
	public:
		Color();

		Color(int r, int g, int b, int a = 255);
	};

	inline
	Mach::Color operator+(const Mach::Color& left, const Mach::Color& right)
	{
		Mach::Color result;
		result.r = std::min(left.r + right.r, 255);
		result.g = std::min(left.g + right.g, 255);
		result.b = std::min(left.b + right.b, 255);
		return result;
	}

	inline
	Mach::Color operator-(const Mach::Color& left, const Mach::Color& right)
	{
		Mach::Color result;
		result.r = std::max(left.r - right.r, 0);
		result.g = std::max(left.g - right.g, 0);
		result.b = std::max(left.b - right.b, 0);
		return result;
	}

	inline
	Mach::Color operator*(const Mach::Color& left, const Mach::Color& right)
	{
		Mach::Color result;
		result.r = std::min(left.r * right.r, 255);
		result.g = std::min(left.g * right.g, 255);
		result.b = std::min(left.b * right.b, 255);
		return result;
	}

	inline
	Mach::Color& operator+=(Mach::Color& left, const Mach::Color& right)
	{
		left.r = std::min(left.r + right.r, 255);
		left.g = std::min(left.g + right.g, 255);
		left.b = std::min(left.b + right.b, 255);
		return left;
	}

	inline
	Mach::Color& operator-=(Mach::Color& left, const Mach::Color& right)
	{
		left.r = std::max(left.r - right.r, 0);
		left.g = std::max(left.g - right.g, 0);
		left.b = std::max(left.b - right.b, 0);
		return left;
	}

	inline
	Mach::Color& operator*=(Mach::Color& left, const Mach::Color& right)
	{
		left.r = std::min(left.r * right.r, 255);
		left.g = std::min(left.g * right.g, 255);
		left.b = std::min(left.b * right.b, 255);
		return left;
	}

	inline
	std::ostream& operator<<(std::ostream& os, const Mach::Color& color)
	{
		os << "Color: [" << color.r << ", " << color.g << ", " << color.b << ", " << color.a << "]";
		return os;
	}

	inline
	bool operator==(const Mach::Color& left, const Mach::Color& right)
	{
		return (left.r == right.r) && (left.g == right.g) && (left.b == right.b) && (left.a == right.a);
	}

	inline
	bool operator!=(const Mach::Color& left, const Mach::Color& right)
	{
		return !operator==(left, right);
	}

}