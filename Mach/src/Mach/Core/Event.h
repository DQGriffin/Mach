#pragma once
#include "..//MachAPI.h"
#include "..//System/Keyboard.h"
#include "..//System/Mouse.h"

namespace Mach
{
	class MACH_API Event
	{
	public:
		enum class Type{KeyEvent, MouseEvent};

		Type type;

		struct KeyEvent
		{
			Keyboard::Key key;
		};

		struct MouseEvent
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