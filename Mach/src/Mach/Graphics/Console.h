#pragma once
#include <string>
#include <vector>
#include "..//MachAPI.h"

namespace Mach
{
	class MACH_API Console
	{
	public:
	private:
		static std::vector<std::string>* m_ConsoleBuffer;
	public:
		static void push(const char* message);
		static void push(std::string& message);
	protected:
		friend class Application;
		static void initialize(std::vector<std::string>* consoleBuffer);
	};
}