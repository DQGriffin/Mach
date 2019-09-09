#pragma once
#include <iostream>
#include "..//MachAPI.h"

namespace Mach {
	template <class T>
	class MACH_API Vector2
	{
	public:
		T x;
		T y;
	public:
		//==========================================================================
		// Construct a Vector2
		//==========================================================================
		Vector2() : x(0), y(0)
		{
		}

		//==========================================================================
		// Construct a Vector2 with the given values
		//==========================================================================
		template <class T>
		Vector2(T x, T y) : x(x), y(y) // Not using {}-notation because we want to allow narrowing (int -> float)
		{
		}

		//==========================================================================
		// Convert a Vector2 of one type to another
		//==========================================================================
		template <class U>
		explicit Vector2<T>(const Vector2<U>& vec) : x(static_cast<T>(vec.x)), y(static_cast<T>(vec.y))
		{
		}

	};

	//==========================================================================
	// Output operator overload
	//==========================================================================
	template <class T>
	std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec)
	{
		os << "[" << vec.x << ", " << vec.y << "]";
		return os;
	}

	//==========================================================================
	// Add one Vector2 to another
	//==========================================================================
	template <class T>
	Vector2<T> operator+(const Vector2<T>& left, const Vector2<T>& right)
	{
		return Vector2<T>(left.x + right.x, left.y + right.y);
	}

	//==========================================================================
	// Add a given value to a Vector2
	//==========================================================================
	template <class T>
	inline Vector2<T> operator+(const Vector2<T>& vec, T value)
	{
		return Vector2<T>(vec.x + value, vec.y + value);
	}

	//==========================================================================
	// Add one Vector2 to another
	//==========================================================================
	template <class T>
	inline Vector2<T>& operator+=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x += right.x;
		left.y += right.y;
		return left;
	}

	//==========================================================================
	// Add a given value to a Vector2
	//==========================================================================
	template <class T>
	inline Vector2<T>& operator+=(Vector2<T>& left, T value)
	{
		left.x += value;
		left.y += value;
		return left;
	}

	//==========================================================================
	// Subtract one Vector2 from another
	//==========================================================================
	template <class T>
	Vector2<T> operator-(const Vector2<T>& left, const Vector2<T>& right)
	{
		return Vector2<T>(left.x - right.x, left.y - right.y);
	}

	//==========================================================================
	// Subtract a given value from a Vector2
	//==========================================================================
	template <class T>
	inline Vector2<T> operator-(const Vector2<T>& vec, T value)
	{
		return Vector2<T>(vec.x - value, vec.y - value);
	}

	//==========================================================================
	// Subtract one Vector2 from another
	//==========================================================================
	template <class T>
	inline Vector2<T>& operator-=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		return left;
	}

	//==========================================================================
	// Subtract a given value from a Vector2
	//==========================================================================
	template <class T>
	inline Vector2<T>& operator-=(Vector2<T>& left, T value)
	{
		left.x -= value;
		left.y -= value;
		return left;
	}

	//==========================================================================
	// Multiply one Vector2 by another
	//==========================================================================
	template <class T>
	Vector2<T> operator*(const Vector2<T>& left, const Vector2<T>& right)
	{
		return Vector2<T>(left.x * right.x, left.y * right.y);
	}

	//==========================================================================
	// Multiply a Vector2 by a given value
	//==========================================================================
	template <class T>
	inline Vector2<T> operator*(const Vector2<T>& vec, T value)
	{
		return Vector2<T>(vec.x * value, vec.y * value);
	}

	//==========================================================================
	// Multiply one Vector2 by another
	//==========================================================================
	template <class T>
	inline Vector2<T>& operator*=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x *= right.x;
		left.y *= right.y;
		return left;
	}

	//==========================================================================
	// Multiply a Vector2 by a given value
	//==========================================================================
	template <class T>
	inline Vector2<T>& operator*=(Vector2<T>& left, T value)
	{
		left.x *= value;
		left.y *= value;
		return left;
	}

	//==========================================================================
	// Divide one Vector2 by another
	//==========================================================================
	template <class T>
	Vector2<T> operator/(const Vector2<T>& left, const Vector2<T>& right)
	{
		return Vector2<T>(left.x / right.x, left.y / right.y);
	}

	//==========================================================================
	// Divide a Vector2 by a given value
	//==========================================================================
	template <class T>
	inline Vector2<T> operator/(const Vector2<T>& vec, T value)
	{
		return Vector2<T>(vec.x / value, vec.y / value);
	}

	//==========================================================================
	// Divide one Vector2 by another
	//==========================================================================
	template <class T>
	inline Vector2<T>& operator/=(Vector2<T>& left, const Vector2<T>& right)
	{
		left.x /= right.x;
		left.y /= right.y;
		return left;
	}

	//==========================================================================
	// Divide a Vector2 by a given value
	//==========================================================================
	template <class T>
	inline Vector2<T>& operator/=(Vector2<T>& left, T value)
	{
		left.x /= value;
		left.y /= value;
		return left;
	}

	//==========================================================================
	// Inequality operator
	//==========================================================================
	template <class T>
	inline bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
	{
		return (left.x != right.x) || (left.y != right.y);
	}

	//==========================================================================
	// Equality operator
	//==========================================================================
	template <class T>
	inline bool operator==(const Vector2<T>& left, const Vector2<T>& right)
	{
		return (left.x == right.x) && (left.y == right.y);
	}

	typedef Vector2<int> Vector2i;
	typedef Vector2<unsigned int> Vector2u;
	typedef Vector2<float> Vector2f;
	typedef Vector2<double> Vector2d;
}