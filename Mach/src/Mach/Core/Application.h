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
// 3. This notice may not be removed or altered from ny source distribution.
//
////////////////////////////////////////////////////////////

#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "..//MachAPI.h"
#include "..//Graphics/FontManager.h"
#include "..//Logging/Logger.h"
#include "../System/InputEngine.h"
#include "..//Graphics/Color.h"
#include "..//Graphics/Renderer.h"
#include "..//Graphics/Window.h"
#include <thread>
#include <functional>
#include <vector>
#include <string>

namespace Mach
{
	class MACH_API Application
	{
	public:
		bool done;
		Mach::Window m_Window;
	private:
		friend class Renderer;
		InputEngine inputEngine;
		std::thread inputThread;
		sf::Clock clock;
		char m_ConsoleInputBuffer[256];
		std::vector<std::string> consoleBuffer;
	public:
		Application();
		virtual ~Application();
		void start();
		virtual void run();
		void exit(int code = 0);
		bool hasEvent();
		Mach::Event getEvent();
		void clearEvents();
		void updateConsole();
	};

	Application* createApplication();

}