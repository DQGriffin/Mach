#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

#include "..//MachAPI.h"
#include "Drawable.h"
#include "Texture.h"
#include "..//System/Vector2.h"


namespace Mach
{
	class MACH_API Sprite : public Drawable
	{
	public:
	private:
		Mach::Texture* m_Texture;
		sf::Sprite m_Sprite;
		Mach::Vector2i m_Position;
	public:
		friend Renderer;
		Sprite();
		Sprite(Mach::Texture& texture);
		Sprite(const Sprite& other);
		void setPosition(int x, int y);
		void setPosition(Mach::Vector2i position);
	protected:
		void update();
		void draw(sf::RenderWindow* window) override;
	};
}