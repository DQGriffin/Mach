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
#include "LogLine.h"

#ifdef MACH_WINDOWS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif // MACH_WINDOWS

#define LOG Mach::LogLine(false, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 2).stream()
#define LOG_INFO Mach::LogLine(false, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 2).stream()
#define LOG_DEBUG Mach::LogLine(false, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 1).stream()
#define LOG_WARN Mach::LogLine(false, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 3).stream()
#define LOG_ERROR Mach::LogLine(false, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 4).stream()
#define LOG_FATAL Mach::LogLine(false, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 5).stream()

#define LOG_IF(boolean_expr) Mach::LogLine(!boolean_expr, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 2).stream()
#define LOG_INFO_IF(boolean_expr) Mach::LogLine(!boolean_expr, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 2).stream()
#define LOG_DEBUG_IF(boolean_expr) Mach::LogLine(!boolean_expr, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 1).stream()
#define LOG_WARN_IF(boolean_expr) Mach::LogLine(!boolean_expr, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 3).stream()
#define LOG_ERROR_IF(boolean_expr) Mach::LogLine(!boolean_expr, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 4).stream()
#define LOG_FATAL_IF(boolean_expr) Mach::LogLine(!boolean_expr, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 5).stream()

#ifndef ASSERT(boolean_expr)
#define ASSERT(boolean_expr) Mach::LogLine(boolean_expr, std::this_thread::get_id(), std::string{__FILE__}, __LINE__, 5).stream()
#endif // !ASSERT(boolean_expr)

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
		//LOG_INFO << "";
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