#include "LogLine.h"

//=================================================================
// Create a log line object
//=================================================================
Mach::LogLine::LogLine(bool ignore, std::thread::id thread_id, std::string file_name, int line_number, int level)
{
#ifdef _DEBUG
	this->ignore = ignore;
	this->thread_id = thread_id;
	this->file_name = file_name;
	this->line_number = line_number;
	this->level = level;
#endif // _DEBUG
}

//=================================================================
// Destructor
// The line is actually logged when the LogLine object goes out of
// scope
//=================================================================
Mach::LogLine::~LogLine()
{
#ifdef _DEBUG
	if (!ignore)
	{
		Logger::log(thread_id, file_name, line_number, level, _stream.str());
	}
#endif // _DEBUG
}

//=================================================================
// Returns the string stream used to store text
//=================================================================
std::ostringstream& Mach::LogLine::stream()
{
	return _stream;
}
