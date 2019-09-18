#pragma once
#include "..//MachAPI.h"
#include "Drawable.h"
#include "Renderer.h";
#include <vector>

namespace Mach
{
	class MACH_API RenderGroup
	{
	private:
		friend class Renderer;
		std::vector<Drawable&> m_Drawables;
	public:
		RenderGroup();
		void add(Drawable& drawable);
	};
}