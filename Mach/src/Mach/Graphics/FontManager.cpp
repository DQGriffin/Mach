#include "FontManager.h"

std::map<std::string, Mach::Font> Mach::FontManager::m_Fonts;

//==========================================================================
// Add a font to the font registry
//==========================================================================
void Mach::FontManager::add(std::string fontName, std::string path)
{

	Mach::Font font{ path };

	if (font.isValid())
	{
		LOG << "Font \"" << fontName << "\" loaded successfully";
		m_Fonts[fontName] = font;
	}
	else
	{
		LOG_ERROR << "Font \"" << fontName << "\" failed to load";
	}
}

//==========================================================================
// Remove a font from the registry
//==========================================================================
void Mach::FontManager::remove(std::string fontName)
{
	std::map<std::string, Mach::Font>::iterator it = m_Fonts.begin();

	while (it != m_Fonts.end())
	{
		if (it->first == fontName)
		{
			m_Fonts.erase(fontName);
		}
		it++;
	}
}

//==========================================================================
// Get a given font
//==========================================================================
Mach::Font* Mach::FontManager::get(std::string fontName)
{
	if (has(fontName))
	{
		return &m_Fonts[fontName];
	}
	return nullptr;
}

//==========================================================================
// Queries whether or not a given font exists in the registry
//==========================================================================
bool Mach::FontManager::has(std::string fontName)
{
	std::map<std::string, Mach::Font>::iterator it = m_Fonts.begin();

	while (it != m_Fonts.end())
	{
		if (it->first == fontName)
		{
			return true;
		}
		it++;
	}
	return false;
}
