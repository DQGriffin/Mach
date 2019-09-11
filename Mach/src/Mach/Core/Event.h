#pragma once
#include "..//MachAPI.h"
#include "..//System/Keyboard.h"

namespace Mach
{
	class MACH_API Event
	{
	public:
		enum class Type{KeyEvent};

		Type type;

		struct KeyEvent
		{
			Keyboard::Key key;
		};

		union
		{
			KeyEvent keyEvent;
		};
	};
}