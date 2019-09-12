#pragma once
#include <vector>
#include <chrono>
#include <map>
#include "..//MachAPI.h"
#include "..//Logging/Logger.h"
#include "Keyboard.h"
#include "..//Core/EventManager.h"

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
		int tickRate; // The update rate in ms
		bool isPolling;
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
		void initializeKeyMapN();
	};
}