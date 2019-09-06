#pragma once
#include "..//MachAPI.h"

namespace Mach
{
	class MACH_API Application
	{
	public:
		Application();
		virtual ~Application();
		virtual void run() = 0;
	};

	Application* createApplication();

}