#include "EventManager.h"

std::queue<Mach::Event> Mach::EventManager::events;

//==========================================================================
// Add an event to the event queue
//==========================================================================
void Mach::EventManager::fireEvent(Mach::Event event)
{
	events.push(event);
}

//==========================================================================
// Query whether or not the Event Manager has events
//==========================================================================
bool Mach::EventManager::hasEvents()
{
	return events.size > 0;
}

//==========================================================================
// Get the event at the front of the queue
//==========================================================================
Mach::Event Mach::EventManager::getEvent()
{
	Mach::Event event = events.front();
	events.pop();
	return event;
}
