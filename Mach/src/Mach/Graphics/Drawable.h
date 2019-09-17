#pragma once
#include "..//MachAPI.h"
#include "Window.h"

namespace Mach
{
	class Drawable
	{
	public:
		virtual ~Drawable(){}
	protected:
		friend class Window;
		virtual void draw(Window& window) {};
	};
}