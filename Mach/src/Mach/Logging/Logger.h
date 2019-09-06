#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include "..//MachAPI.h"

#ifdef MACH_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif // MACH_WINDOWS


namespace Mach
{
	struct LogLevel { static const int MACH_DEBUG = 1; static const int MACH_INFO = 2; static const int MACH_WARNING = 3; static const int MACH_ERROR = 4; static const int MACH_FATAL = 5; };

	class MACH_API Logger
	{
	public:
		enum class LogMode{Console, File};
	private:
		static LogMode m_Mode;
		static std::ofstream os;
		static bool initialized;
		static int maxLevel;
		static bool useLocalTime;
		static std::string m_Filepath;
	public:
		static void initialize(LogMode mode, const char* filepath = "");
		static void log(std::thread::id thread_id, std::string file_name, int line_number, int level, std::string message);
		static void set_max_level(int max_level);
	private:
		static std::string formatLogLine(std::thread::id thread_id, std::string file_name, int line_number, std::string message);
		static std::string levelToString(int level);
		static std::string extractFileName(std::string fileName);
		static std::string timestamp();
		static std::string timestampUTC();
		static std::string timestampLocal();
		static void logToConsole(std::string timestamp, std::string logLevel, std::string log);
		static void logToFile(std::string timestamp, std::string logLevel, std::string log);
		static void initializeConsole();
		static void setConsoleColor(std::string logLevel);
		static void resetConsoleColor();
	};
}