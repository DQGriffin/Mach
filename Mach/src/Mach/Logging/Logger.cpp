#include "Logger.h"

std::ofstream Mach::Logger::os;
bool Mach::Logger::initialized;
bool Mach::Logger::useLocalTime;
Mach::Logger::LogMode Mach::Logger::m_Mode;
int Mach::Logger::maxLevel;
std::string Mach::Logger::m_Filepath;

//=================================================================
// Initialze the logger
//=================================================================
void Mach::Logger::initialize(LogMode mode, const char* filepath)
{
#ifdef _DEBUG
	if (!initialized)
	{
		m_Mode = mode;
		m_Filepath = filepath;
		useLocalTime = false;
		initializeConsole();
	}
#endif // _DEBUG

}

//=================================================================
// Log a message to the stream
//=================================================================
void Mach::Logger::log(std::thread::id thread_id, std::string file_name, int line_number, int level, std::string message)
{
#ifdef _DEBUG
	std::string _timestamp = timestamp();
	std::string _level = levelToString(level);
	std::string _log_data = formatLogLine(thread_id, file_name, line_number, message);

	if (m_Mode == LogMode::Console)
	{
		logToConsole(_timestamp, _level, _log_data);
	}
	else
	{
		logToFile(_timestamp, _level, _log_data);
	}
#endif // _DEBUG

}

//=================================================================
// Set the maximum allowed log level
//=================================================================
void Mach::Logger::set_max_level(int max_level)
{
	Mach::Logger::maxLevel = max_level;
}

//=================================================================
// Returns the given log data as a formatted std::string
//=================================================================
std::string Mach::Logger::formatLogLine(std::thread::id thread_id, std::string file_name, int line_number, std::string message)
{
	std::stringstream stream;
	stream << "[" << thread_id << "] ";
	stream << "[" << extractFileName(file_name) << "@" << line_number << "] ";
	stream << message;	
	return stream.str();
}

//=================================================================
// Returns the given log level as a std::string
//=================================================================
std::string Mach::Logger::levelToString(int level)
{
	switch (level)
	{
	case 1:
		return "DEBUG";
		break;
	case 2:
		return "INFO ";
		break;
	case 3:
		return "WARN ";
		break;
	case 4:
		return "ERROR";
		break;
	case 5:
		return "FATAL";
		break;
	default:
		return "?????";
		break;
	}
}

//=================================================================
// Extracts the file name from its path
//=================================================================
std::string Mach::Logger::extractFileName(std::string fileName)
{
#ifdef _WIN32
	int line_sep_pos = fileName.find_last_of("\\") + 1;
#endif // _WIN32
#ifndef _WIN32
	int line_sep_pos = file_name.find_last_of("/") + 1;
#endif // !_WIN32

	fileName = fileName.substr(line_sep_pos, fileName.length());

	int dot_pos = fileName.find_first_of(".");
	fileName = fileName.substr(0, dot_pos);

	return fileName;
}

//=================================================================
// Returns the time as a std::string
//=================================================================
std::string Mach::Logger::timestamp()
{
	if (useLocalTime)
	{
		return timestampLocal();
	}
	else
	{
		return timestampUTC();
	}
}

//=================================================================
// Returns GMT time as a std::string
//=================================================================
std::string Mach::Logger::timestampUTC()
{
#ifdef MACH_WINDOWS
	struct tm newtime;
	__int64 ltime;
	char buf[32];

	_time64(&ltime);
	_gmtime64_s(&newtime, &ltime);
	//asctime_s(buf, sizeof(buf), &newtime);
	strftime(buf, sizeof(buf), "%Y-%m-%d %X", &newtime);

	return std::string{ buf };
#endif // _WIN32
}

//=================================================================
// Returns local time as a std::string
//=================================================================
std::string Mach::Logger::timestampLocal()
{
#ifdef MACH_WINDOWS
	auto now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);
	tm ltm;
	localtime_s(&ltm, &time_now);
#endif // MACH_WINDOWS
#ifdef MACH_LINUX
	time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	tm* ltm = localtime(&now);
#endif // !MACH_LINUX

	char buffer[256];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", &ltm);
	std::string _timestamp(buffer);
	return _timestamp;
}

//=================================================================
// Logs to the console
//=================================================================
void Mach::Logger::logToConsole(std::string timestamp, std::string logLevel, std::string log)
{

#ifdef MACH_WINDOWS
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	
	std::cout << timestamp << " ";
	setConsoleColor(logLevel);
	std::cout << logLevel << " ";
	resetConsoleColor();
	std::cout << log << "\n";
#endif // MACH_WINDOWS
}

//=================================================================
// Logs to the log file
//=================================================================
void Mach::Logger::logToFile(std::string timestamp, std::string logLevel, std::string log)
{
}

//=================================================================
// Creates and attaches a console
// Windows only for now
//=================================================================
void Mach::Logger::initializeConsole()
{
	int consoleHandle;
	long lStdHandle;
	CONSOLE_SCREEN_BUFFER_INFO console_info;
	FILE* fp;

	// Allocate a console for the application
	// AllocConsole returns true if a console was successfully allocated,
	// false if the application already has an allocated console
	bool consoleAllocated = AllocConsole();

	if (consoleAllocated)
	{
		// Ensure the screen buffer is large enough to let us scroll
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&console_info);
		console_info.dwSize.Y = 5000; // 5000 is the max number of lines of output
		SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), console_info.dwSize);

		// Redirect unbuffered STDOUT to the console
		lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
		consoleHandle = _open_osfhandle(lStdHandle, _O_TEXT);

		fp = _fdopen(consoleHandle, "w");
		*stdout = *fp;
		setvbuf(stdout, nullptr, _IONBF, _O_TEXT);
		std::ios::sync_with_stdio();
	}
	else
	{
		// The application has already been allocated a console
	}
}

//=================================================================
// Set the console color appropriately
//=================================================================
void Mach::Logger::setConsoleColor(std::string logLevel)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (logLevel == "DEBUG")
	{
		//SetConsoleTextAttribute(hConsole, 13);
	}
	else if (logLevel == "INFO ")
	{
		//SetConsoleTextAttribute(hConsole, 11);
	}
	else if (logLevel == "WARN ")
	{
		SetConsoleTextAttribute(hConsole, 14);
	}
	else if (logLevel == "ERROR")
	{
		SetConsoleTextAttribute(hConsole, 12);
	}
	else if (logLevel == "FATAL")
	{
		SetConsoleTextAttribute(hConsole, 207);
	}
}

//=================================================================
// Reset the console color to white
//=================================================================
void Mach::Logger::resetConsoleColor()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);
}

