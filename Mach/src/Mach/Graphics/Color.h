#pragma once
#include "..//MachAPI.h"

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

	Color operator+(const Color& left, const Color& right)
	{
		Color result;
		result.r = left.r + right.r;
		result.g = left.g + right.g;
		result.b = left.b + right.b;		
		return result;
	}

	Color operator-(const Color& left, const Color& right)
	{
		Color result;
		result.r = left.r - right.r;
		result.g = left.g - right.g;
		result.b = left.b - right.b;		
		return result;
	}

	Color operator*(const Color& left, const Color& right)
	{
		Color result;
		result.r = left.r * right.r;
		result.g = left.g * right.g;
		result.b = left.b * right.b;		
		return result;
	}

	Color& operator+=(Color& left, const Color& right)
	{
		left.r += right.r;
		left.g += right.g;
		left.b += right.b;
		return left;
	}

	Color& operator-=(Color& left, const Color& right)
	{
		left.r -= right.r;
		left.g -= right.g;
		left.b -= right.b;
		return left;
	}

	Color& operator*=(Color& left, const Color& right)
	{
		left.r *= right.r;
		left.g *= right.g;
		left.b *= right.b;
		return left;
	}

	bool operator==(const Color& left, const Color& right)
	{
		return (left.r == right.r) && (left.g == right.g) && (left.b == right.b) && (left.a == right.a);
	}

	bool operator!=(const Color& left, const Color& right)
	{
		return !operator==(left, right);
	}
}