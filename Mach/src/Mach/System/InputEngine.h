#pragma once
#include <vector>
#include <chrono>
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
		std::vector<Keyboard::Key> keysPressed;
		int tickRate; // The update rate in ms
		bool isPolling;
		
	public:
		InputEngine(int tickRate = 200);
		void pollInput();
		void pollKeyInput();
		void pollMouseInput();
		void poll();
	private:
		void isKeyPressed();
	};
}