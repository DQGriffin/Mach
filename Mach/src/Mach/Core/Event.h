////////////////////////////////////////////////////////////
//
// Mach Engine
// Copyright (C) 2019 D'Quavius J. Griffin
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#pragma once
#include "..//MachAPI.h"
#include "..//System/Keyboard.h"
#include "..//System/Mouse.h"

namespace Mach
{
	class MACH_API Event
	{
	private:
		struct KeyPressed
		{
			Keyboard::Key key;
		};

		struct KeyReleased
		{
			Keyboard::Key key;
		};

		struct MouseButtonPressed
		{
			Mouse::Button button;
			int x;
			int y;
		};

		struct MouseButtonReleased
		{
			Mouse::Button button;
			int x;
			int y;
		};

		struct MouseMove
		{
			int x;
			int y;
			int horizontalDelta;
			int verticalDelta;
		};

		struct Resized
		{
			int width;
			int height;
		};

		struct Exit
		{
			int code;
		};
	public:
		enum class Type{KeyPressed, KeyReleased, MouseButtonPressed, MouseButtonReleased, MouseMove, Exit, Resized};

		Type type;

		union
		{
			KeyPressed keyPressedEvent;
			KeyReleased keyReleasedEvent;
			MouseButtonPressed mouseClickEvent;
			MouseButtonReleased mouseButtonReleased;
			MouseMove mouseMoveEvent;
			Exit exit;
			Resized resized;
		};
	};

}