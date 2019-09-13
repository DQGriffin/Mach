#pragma once
#include "..//MachAPI.h"
#include "..//System/Keyboard.h"
#include "..//System/Mouse.h"

namespace Mach
{
	class MACH_API Event
	{
	public:
		enum class Type{KeyEvent, MouseClickEvent};

		Type type;

		struct KeyEvent
		{
			Keyboard::Key key;
		};

		struct MouseClickEvent
		{
			Mouse::Button button;
			int x;
			int y;
		};

		union
		{
			KeyEvent keyEvent;
		};
	};
}