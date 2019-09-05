#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "..//MachAPI.h"

namespace Mach
{
	class MACH_API Logger
	{
	public:
	private:
		static enum class LogMode{Console, File};
		static LogMode mode;
		static std::ofstream os;
	public:
		void initialize(LogMode mode, const char* filepath = "");
	};
}