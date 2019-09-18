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
#include "..//Logging/Logger.h"
#include "..//System/Vector2.h"
#include "Drawable.h"

namespace Mach
{
	class MACH_API Window
	{
	public:
	private:
		Vector2i m_Size;
		Vector2i m_Position;
		std::string m_Title;
	protected:
		friend class Drawable;
		sf::RenderWindow m_RenderWindow;		
	public:
		Window();
		Window(int x, int y, int width, int height);
		Window(int x, int y, int width, int height, std::string title);
		Window(int x, int y, int width, int height, const char* title);
		void revalidate();
		void setVsyncEnabled(bool enabled);
		void setSize(int x, int y);
		void setSize(Vector2i size);
		void setPosition(int x, int y);
		void setPosition(Vector2i position);
		void draw(Drawable& drawable);
	private:
	};
}