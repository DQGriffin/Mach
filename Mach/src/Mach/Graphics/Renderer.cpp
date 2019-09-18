#include "Renderer.h"

sf::RenderWindow* Mach::Renderer::m_RenderWindow;

//==========================================================================
// Initialize the renderer
//==========================================================================
void Mach::Renderer::initialize(sf::RenderWindow* renderWindow)
{
	m_RenderWindow = renderWindow;
}

//==========================================================================
// Clear the screen
//
// Call before rendering elements of a new frame
//==========================================================================
void Mach::Renderer::clear()
{
	m_RenderWindow->clear();
}

//==========================================================================
// Render a Mach drawable
//==========================================================================
void Mach::Renderer::render(Mach::Drawable& drawable)
{
	drawable.draw(m_RenderWindow);
	LOG_WARN << "Rendering has not yet been implemented";
}

//==========================================================================
// Render a group of drawables
//==========================================================================
void Mach::Renderer::render(Mach::RenderGroup& renderGroup)
{
	for (Drawable& drawable : renderGroup.m_Drawables)
	{
		drawable.draw(m_RenderWindow);
	}
}

//==========================================================================
// Display the frame
//==========================================================================
void Mach::Renderer::display()
{
	m_RenderWindow->display();
}
