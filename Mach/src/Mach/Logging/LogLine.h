#pragma once
#include "..//MachAPI.h"
#include "Logger.h"

namespace Mach
{
	class MACH_API LogLine
	{
	private:
		std::thread::id thread_id;
		std::string file_name;
		int line_number;
		int level;
		std::ostringstream _stream;
		bool ignore;
	public:
		LogLine(bool ignore, std::thread::id thread_id, std::string file_name, int line_number, int level);
		~LogLine();
		std::ostringstream& stream();
	};
}