#pragma once
#include "..//MachAPI.h"
#include "..//System/Keyboard.h"
#include "..//System/Mouse.h"

namespace Mach
{
	class MACH_API Event
	{
	public:
		enum class Type{KeyEvent, MouseClickEvent, MouseMoveEvent};

		Type type;

		struct KeyEvent
		{
			Keyboard::Key key;
		};

		struct KeyReleasedEvent
		{
			Keyboard::Key key;
		};

		struct MouseClickEvent
		{			
			Mouse::Button button;			
			int x;
			int y;
		};

		struct MouseMoveEvent
		{
			int x;
			int y;
			int horizontalDelta;
			int verticalDelta;
		};

		union
		{
			KeyEvent keyEvent;
			KeyReleasedEvent keyReleasedEvent;
			MouseClickEvent mouseClickEvent;
			MouseMoveEvent mouseMoveEvent;
		};
	};
}