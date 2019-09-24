#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "..//MachAPI.h"
#include "..//Logging/Logger.h"
#include "Drawable.h"
#include "RenderGroup.h"

namespace Mach
{
	class MACH_API Renderer
	{
	private:
		static sf::RenderWindow* m_RenderWindow;
	protected:
		friend class Drawable;
		friend class Application;
		static void initialize(sf::RenderWindow* renderWindow);
	public:
		static void clear();
		static void render(Mach::Drawable& drawable);
		static void render(Mach::RenderGroup& renderGroup);
		static void display();
	};
}