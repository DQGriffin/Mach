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
	#include <Windows.h>
#endif

namespace Mach
{
	class MACH_API InputEngine
	{
	public:
	private:
		std::vector<Keyboard::Key> keysDown;		
		std::map<Keyboard::Key, int> keyMap;
		std::map<Mouse::Button, int> mouseButtonMap;
		int tickRate; // The update rate in ms
		bool isPolling;
		Vector2i previousMousePosition;
	public:
		InputEngine(int tickRate = 80);
		void pollInput();
		void pollKeyInput();
		void pollKeysDown();
		void pollMouseInput();
		void poll();
	private:
		void isKeyPressed();
		void initializeKeyMap();
		void initializeMouseButtonMap();
	};
}