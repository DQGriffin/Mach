#pragma once
#include "..//MachAPI.h"

namespace Mach
{
	class MACH_API Drawable
	{
	public:
		virtual ~Drawable() {};
	protected:
		friend class Window;
		virtual void draw(Window* window) {};
	};
}