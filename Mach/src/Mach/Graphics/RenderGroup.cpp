#include "RenderGroup.h"

Mach::RenderGroup::RenderGroup()
{
}

//==========================================================================
// Add a drawable to the RenderGroup
//==========================================================================
void Mach::RenderGroup::add(Drawable& drawable)
{
	m_Drawables.push_back(&drawable);
}
