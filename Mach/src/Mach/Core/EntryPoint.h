#pragma once
#include "Application.h"
#include "..//Logging/Logger.h"

#if MACH_WINDOWS

extern Mach::Application* Mach::createApplication();

int main()
{
	Mach::Logger::initialize(Mach::Logger::LogMode::Console);
	auto app = Mach::createApplication();
	app->run();
	delete app;
}

#endif // MACH_WINDOWS
