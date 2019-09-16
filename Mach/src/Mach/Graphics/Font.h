#pragma once
#include "..//MachAPI.h""
#include "..//Logging/Logger.h"
#include <SFML/Graphics/Font.hpp>
#include <string>

namespace Mach
{
	class MACH_API Font
	{
	public:
	private:
		sf::Font m_Font;
	public:
		Font();
		Font(std::string path);
		sf::Font* get();
	};
}