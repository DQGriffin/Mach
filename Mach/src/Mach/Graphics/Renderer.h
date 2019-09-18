#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "..//MachAPI.h"
#include "..//Logging/Logger.h"
#include "Drawable.h"

namespace Mach
{
	class MACH_API Renderer
	{
	private:
		static sf::RenderWindow* m_RenderWindow;
	protected:
		friend class Drawable;
	public:
		static void initialize(sf::RenderWindow* renderWindow);
		static void clear();
		static void render(Mach::Drawable& drawable);
		static void display();
	};
}