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
#include <vector>
#include <chrono>
#include <map>
#include "..//MachAPI.h"
#include "..//Logging/Logger.h"
#include "..//Core/EventManager.h"
#include "Vector2.h"
#include "Keyboard.h"
#include "Mouse.h"

#if MACH_WINDOWS
	#define WIN32_LEAN_AND_MEAN
	#include <Windows.h>
#endif

namespace Mach
{
	class MACH_API InputEngine
	{
	public:
	private:
		std::vector<Keyboard::Key> keysDown;		
		std::vector<Mouse::Button> mouseButtonsDown;
		std::map<Keyboard::Key, int> keyMap;
		std::map<Mouse::Button, int> mouseButtonMap;
		int tickRate; // The update rate in ms
		bool isPolling;
		Vector2i previousMousePosition;
	public:
		InputEngine(int tickRate = 80);		
		void pollKeyInput();		
		void pollMouseInput();
		void poll();
	private:
		void initializeKeyMap();
		void initializeMouseButtonMap();
		void setKeyDown(Keyboard::Key key);
		bool keyDown(Keyboard::Key key);
		void setMouseButtonDown(Mouse::Button button);
		bool buttonDown(Mouse::Button button);
	};
}