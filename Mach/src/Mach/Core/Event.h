#pragma once
#include "..//MachAPI.h"
#include "..//System/Keyboard.h"
#include "..//System/Mouse.h"

namespace Mach
{
	class MACH_API Event
	{
	public:
		enum class Type{KeyPressedEvent, KeyReleasedEvent, MouseClickEvent, MouseMoveEvent};

		Type type;

		struct KeyPressedEvent
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
			KeyPressedEvent keyEvent;
			KeyReleasedEvent keyReleasedEvent;
			MouseClickEvent mouseClickEvent;
			MouseMoveEvent mouseMoveEvent;
		};
	};
}