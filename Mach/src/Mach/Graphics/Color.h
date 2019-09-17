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
}