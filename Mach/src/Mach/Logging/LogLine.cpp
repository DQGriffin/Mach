#include "LogLine.h"

//=================================================================
// Create a log line object
//=================================================================
Mach::LogLine::LogLine(bool ignore, std::thread::id thread_id, std::string file_name, int line_number, int level)
{
	this->ignore = ignore;
	this->thread_id = thread_id;
	this->file_name = file_name;
	this->line_number = line_number;
	this->level = level;
}

//=================================================================
// Destructor
// The line is actually logged when the LogLine object goes out of
// scope
//=================================================================
Mach::LogLine::~LogLine()
{
	if (!ignore)
	{
		Logger::log(thread_id, file_name, line_number, level, _stream.str());
	}
}

//=================================================================
// Returns the string stream used to store text
//=================================================================
std::ostringstream& Mach::LogLine::stream()
{
	return _stream;
}
