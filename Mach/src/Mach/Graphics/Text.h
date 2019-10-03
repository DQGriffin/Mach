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
#include "..//MachAPI.h"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "..//System/Vector2.h"
#include "Drawable.h"
#include "Color.h"
#include "Font.h"
#include "FontManager.h"
#include "Window.h"
#include "..//Core/Application.h"
#include <string>

namespace Mach
{
	class MACH_API Text : public Drawable
	{
	public:
	private:
		Vector2i m_Position;
		int m_FontSize;
		Color m_Color;
		sf::Text m_TextObject;
		Mach::Font* m_Font;
		std::string m_String;
	public:
		Text();
		Text(int x, int y, std::string text, Mach::Font* font, int fontSize, Mach::Color color = Mach::Color::White);
		Text(int x, int y, const char* text, Mach::Font* font, int fontSize, Mach::Color color = Mach::Color::White);
		void setPosition(int x, int y);
		void setPosition(Vector2i position);
		void setFont(Mach::Font* font);
		void setColor(Mach::Color color);
		Mach::Vector2i getPosition();
		Mach::Vector2i getPosition() const;
		std::string getString();
		std::string getString() const;
		void draw(sf::RenderWindow* window) override;
	private:
		void update();
	};
}