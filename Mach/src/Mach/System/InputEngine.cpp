#include "InputEngine.h"

//==========================================================================
// Create an InputEngine object
//==========================================================================
Mach::InputEngine::InputEngine(int tickRate)
{
	this->tickRate = tickRate;
	isPolling = true;
}

//==========================================================================
// Poll for input
//==========================================================================
void Mach::InputEngine::pollInput()
{
}

//==========================================================================
// Poll for keyboard input
//==========================================================================
void Mach::InputEngine::pollKeyInput()
{
#if MACH_WINDOWS
	if (GetKeyState('A') & 0x8000)
	{
		LOG << "a pressed";
		// Fire an event
		Mach::Event event;
		event.keyEvent.key = Keyboard::Key::A;
		event.type = Event::Type::KeyEvent;
		Mach::EventManager::fireEvent(event);
	}
#endif;
}

//==========================================================================
// Poll for mouse input
//==========================================================================
void Mach::InputEngine::pollMouseInput()
{
}

//==========================================================================
// Poll for input
//==========================================================================
void Mach::InputEngine::poll()
{
	while (isPolling)
	{
		//LOG << "Input Engine polling";
		pollKeyInput();
		std::this_thread::sleep_for(std::chrono::milliseconds(tickRate));
	}
}
