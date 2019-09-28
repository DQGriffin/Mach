#include "Console.h"

std::vector<std::string>* Mach::Console::m_ConsoleBuffer;

//==========================================================================
// Push a message to the console
//==========================================================================
void Mach::Console::push(const char* message)
{
	m_ConsoleBuffer->push_back(message);
}

//==========================================================================
// Push a message to the console
//==========================================================================
void Mach::Console::push(std::string& message)
{
	m_ConsoleBuffer->push_back(message);
}

//==========================================================================
// Initialize the console
//==========================================================================
void Mach::Console::initialize(std::vector<std::string>* consoleBuffer)
{
	m_ConsoleBuffer = consoleBuffer;
}
