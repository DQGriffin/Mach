#include "Window.h"

//==========================================================================
// Window constructor
//==========================================================================
Mach::Window::Window()
{
}

//==========================================================================
// Window constructor
//==========================================================================
Mach::Window::Window(int x, int y, int width, int height)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Size.x = width;
	m_Size.y = height;
	m_Title = "";
}

//==========================================================================
// Window constructor
//==========================================================================
Mach::Window::Window(int x, int y, int width, int height, std::string title)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Size.x = width;
	m_Size.y = height;
	m_Title = title;
}

//==========================================================================
// Window constructor
//==========================================================================
Mach::Window::Window(int x, int y, int width, int height, const char* title)
{
	m_Position.x = x;
	m_Position.y = y;
	m_Size.x = width;
	m_Size.y = height;
	m_Title = title;
}

//==========================================================================
// Copy assignment
//==========================================================================
void Mach::Window::operator=(const Mach::Window& other)
{
	m_Position = other.m_Position;
	m_Size = other.m_Size;
	m_Title = other.m_Title;
}

//==========================================================================
// Create (or recreate) the window
//==========================================================================
void Mach::Window::revalidate()
{
	m_RenderWindow.create(sf::VideoMode(m_Size.x, m_Size.y), m_Title);
	m_RenderWindow.setPosition(sf::Vector2i(m_Position.x, m_Position.y));
}

//==========================================================================
// Enable or disable vertical sync
//==========================================================================
void Mach::Window::setVsyncEnabled(bool enabled)
{
	m_RenderWindow.setVerticalSyncEnabled(enabled);
}

//==========================================================================
// Set the size of the window
//==========================================================================
void Mach::Window::setSize(int x, int y)
{
	m_Size.x = x;
	m_Size.y = y;
	revalidate();
}

//==========================================================================
// Set the size of the window
//==========================================================================
void Mach::Window::setSize(Vector2i size)
{
	m_Size = size;
	revalidate();
}

//==========================================================================
// Set the position of the window
//==========================================================================
void Mach::Window::setPosition(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
	revalidate();
}

//==========================================================================
// Set the position of the window
//==========================================================================
void Mach::Window::setPosition(Vector2i position)
{
	m_Position = position;
	revalidate();
}

//==========================================================================
// Draw a drawable to the window
//==========================================================================
void Mach::Window::draw(Mach::Drawable& drawable)
{
	drawable.draw(&m_RenderWindow);
}

void Mach::Window::update()
{
	// For debug purposes
	sf::CircleShape shape(5.f);
	shape.setFillColor(sf::Color::Green);

	if (m_RenderWindow.isOpen())
	{
		sf::Event event;

		while (m_RenderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				// The window is closing
				Mach::Event event;
				event.type = Mach::Event::Type::Exit;
				event.exit.code = 0;
				EventManager::fireEvent(event);
			}
			else if (event.type == sf::Event::Resized)
			{
				sf::Vector2f size = static_cast<sf::Vector2f>(m_RenderWindow.getSize());
				sf::View view = sf::View(sf::FloatRect(0.f, 0.f, size.x, size.y));
				m_RenderWindow.setView(view);
			}
		}

		m_RenderWindow.draw(shape);
	}
}
