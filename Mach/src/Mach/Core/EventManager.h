#pragma once
#include <queue>
#include "..//Logging/Logger.h"
#include "Event.h"

namespace Mach
{
	class EventManager
	{
	public:
		static void fireEvent(Mach::Event event);
		static bool hasEvents();
		static Mach::Event getEvent();
	private:
		static std::queue<Event> events;
	};
}