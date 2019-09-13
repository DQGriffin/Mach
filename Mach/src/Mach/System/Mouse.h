#pragma once
#include "..//MachAPI.h"
//#include "..//Core/EventManager.h"
#include "Vector2.h"

namespace Mach
{
	class Mouse
	{
	public:
		static enum Button { LeftButton, RightButton, MiddleButton, Extra1, Extra2 };
	public:
		static void click(int x, int y, Button button = Button::LeftButton);
		static void click(Vector2i position, Button button = Button::LeftButton);
	};
}