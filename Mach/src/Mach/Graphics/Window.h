#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "..//MachAPI.h"
#include "..//Logging/Logger.h"
#include "..//System/Vector2.h"

namespace Mach
{
	class MACH_API Window
	{
	public:
	private:
		Vector2i m_Size;
		Vector2i m_Position;
		std::string m_Title;
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
	private:
	};
}