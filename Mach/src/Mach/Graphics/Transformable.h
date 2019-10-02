#pragma once
#include "..//MachAPI.h"
#include "..//System/Vector2.h"

namespace Mach
{
	class MACH_API Transformable
	{
	public:
	private:
		Vector2i m_Position;
		Vector2i m_Origin;
		Vector2i m_Scale;
		float m_Rotation;
	public:
		Transformable();
		void setPosition(int x, int y);
		void setPosition(Vector2i position);
		void setOrigin(int x, int y);
		void setOrigin(Vector2i origin);
		void setRotation(float rotation);
		void setScale(int x, int y);
		void setScale(Vector2i scale);
		Mach::Vector2i getPosition();
		Mach::Vector2i getPosition() const;
		Mach::Vector2i getOrigin();
		Mach::Vector2i getOrigin() const;
		Mach::Vector2i getScale();
		Mach::Vector2i getScale() const;
		float getRotation();
		float getRotation() const;
	};
}