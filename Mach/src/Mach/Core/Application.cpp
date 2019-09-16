#include "Application.h"

//==========================================================================
// Application constructor
//==========================================================================
Mach::Application::Application()
{
	//derivedRun = runFunc;

	inputThread = std::thread(std::bind(&InputEngine::poll, inputEngine));

	done = false;
	LOG << "Application::Application()";
}

//==========================================================================
// Application destructor
//==========================================================================
Mach::Application::~Application()
{
	LOG << "Application::~Application()";
}

//==========================================================================
// Currently unused
//==========================================================================
void Mach::Application::run()
{
	
}

//==========================================================================
// Exit the application with the given exit code
//==========================================================================
void Mach::Application::exit(int code)
{
	// Do something with the exit code
	done = true;
}

//==========================================================================
// Query whether or not there are events in the queue
//==========================================================================
bool Mach::Application::hasEvent()
{
	return EventManager::hasEvents();
}

//==========================================================================
// Get the event at the front of the queue
//==========================================================================
Mach::Event Mach::Application::getEvent()
{
	return EventManager::getEvent();
}

//==========================================================================
// Clear all events from the queue
//==========================================================================
void Mach::Application::clearEvents()
{
	EventManager::clearEvents();
}
