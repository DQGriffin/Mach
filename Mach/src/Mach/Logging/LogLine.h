////////////////////////////////////////////////////////////
//
// Mach Engine
// Copyright (C) 2019 D'Quavius J. Griffin
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

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