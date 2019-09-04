#pragma once
#include "Application.h"

#if MACH_WINDOWS

extern Mach::Application* Mach::createApplication();

int main()
{
	auto app = Mach::createApplication();
	app->run();
	delete app;
}

#endif // MACH_WINDOWS
