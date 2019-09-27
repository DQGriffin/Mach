#pragma once
#include "..//MachAPI.h"
#include "..//System/Vector2.h"
#include <SFML/Graphics/Texture.hpp>
#include <string>

namespace Mach
{
	class MACH_API Texture
	{
	public:
	private:
		sf::Texture m_Texture;
	public:
		friend class Sprite;
		Texture();
		Texture(const std::string& path);
		Texture(const Texture& other);
		void operator=(const Texture& other);
		bool create(unsigned int width, unsigned int height);
		bool loadFromFile(std::string path);
		Mach::Vector2i getSize();
	protected:
		sf::Texture* get();
	};
}