#pragma once
#include <iostream>

namespace Mach {
	template <class T>
	class Vector3
	{
	public:
		T x;
		T y;
		T z;
	public:
		//==========================================================================
		// Construct a Vector3
		//==========================================================================
		Vector3() : x{ 0 }, y{ 0 }, z{ 0 }
		{
		}

		//==========================================================================
		// Construct a Vector3 with the given values
		//==========================================================================
		template <class T>
		Vector3(T x, T y, T z) : x{ x }, y{ y }, z{ z }
		{
		}

		//==========================================================================
		// Convert a Vector3 of one type to another
		//==========================================================================
		template <class U>
		explicit Vector3<T>(const Vector3<U>& vec) : x(static_cast<T>(vec.x)), y(static_cast<T>(vec.y)), z(static_cast<T>(vec.z))
		{
		}
	};

	//==========================================================================
	// Output operator overload
	//==========================================================================
	template <class T>
	std::ostream& operator<<(std::ostream& os, const Vector3<T>& vec)
	{
		os << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
		return os;
	}

	//==========================================================================
	// Add one Vector3 to another
	//==========================================================================
	template <class T>
	inline Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right)
	{
		return Vector3<T>(left.x + right.x, left.y + right.y, left.z + right.z);
	}

	//==========================================================================
	// Add a given value to a Vector3
	//==========================================================================
	template <class T>
	inline Vector3<T> operator+(const Vector3<T>& vec, T value)
	{
		return Vector3<T>(vec.x + value, vec.y + value, vec.z + value);
	}

	//==========================================================================
	// Add one Vector3 to another
	//==========================================================================
	template <class T>
	inline Vector3<T>& operator+=(Vector3<T>& left, const Vector3<T>& right)
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		return left;
	}

	//==========================================================================
	// Add a given value to a Vector3
	//==========================================================================
	template <class T>
	inline Vector3<T>& operator+=(Vector3<T>& left, T value)
	{
		left.x += value;
		left.y += value;
		left.z += value;
		return left;
	}

	//==========================================================================
	// Subtract one Vector3 from another
	//==========================================================================
	template <class T>
	inline Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right)
	{
		return Vector3<T>(left.x - right.x, left.y - right.y, left.z - right.z);
	}

	//==========================================================================
	// Subtract a given value from a Vector3
	//==========================================================================
	template <class T>
	inline Vector3<T> operator-(const Vector3<T>& vec, T value)
	{
		return Vector3<T>(vec.x - value, vec.y - value, vec.z - value);
	}

	//==========================================================================
	// Subtract one Vector3 from another
	//==========================================================================
	template <class T>
	inline Vector3<T>& operator-=(Vector3<T>& left, const Vector3<T>& right)
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;
		return left;
	}

	//==========================================================================
	// Subtract a given value from a Vector3
	//==========================================================================
	template <class T>
	inline Vector3<T>& operator-=(Vector3<T>& left, T value)
	{
		left.x -= value;
		left.y -= value;
		left.z -= value;
		return left;
	}

	//==========================================================================
	// Multiply one Vector3 by another
	//==========================================================================
	template <class T>
	inline Vector3<T> operator*(const Vector3<T>& left, const Vector3<T>& right)
	{
		return Vector3<T>(left.x * right.x, left.y * right.y, left.z * right.z);
	}

	//==========================================================================
	// Multiply a Vector3 by a given value
	//==========================================================================
	template <class T>
	inline Vector3<T> operator*(const Vector3<T>& vec, T value)
	{
		return Vector3<T>(vec.x * value, vec.y * value, vec.z * value);
	}

	//==========================================================================
	// Multiply one Vector3 by another
	//==========================================================================
	template <class T>
	inline Vector3<T>& operator*=(Vector3<T>& left, const Vector3<T>& right)
	{
		left.x *= right.x;
		left.y *= right.y;
		left.z *= right.z;
		return left;
	}

	//==========================================================================
	// Multiply a Vector3 by a given value
	//==========================================================================
	template <class T>
	inline Vector3<T>& operator*=(Vector3<T>& left, T value)
	{
		left.x *= value;
		left.y *= value;
		left.z *= value;
		return left;
	}

	//==========================================================================
	// Divide one Vector3 by another
	//==========================================================================
	template <class T>
	inline Vector3<T> operator/(const Vector3<T>& left, const Vector3<T>& right)
	{
		return Vector3<T>(left.x / right.x, left.y / right.y, left.z / right.z);
	}

	//==========================================================================
	// Divide a Vector3 by a given value
	//==========================================================================
	template <class T>
	inline Vector3<T> operator/(const Vector3<T>& vec, T value)
	{
		return Vector3<T>(vec.x / value, vec.y / value, vec.z / value);
	}

	//==========================================================================
	// Divide one Vector3 by another
	//==========================================================================
	template <class T>
	inline Vector3<T>& operator/=(Vector3<T>& left, const Vector3<T>& right)
	{
		left.x /= right.x;
		left.y /= right.y;
		left.z /= right.z;
		return left;
	}

	//==========================================================================
	// Divide a Vector3 by a given value
	//==========================================================================
	template <class T>
	inline Vector3<T>& operator/=(Vector3<T>& left, T value)
	{
		left.x /= value;
		left.y /= value;
		left.z /= value;
		return left;
	}

	//==========================================================================
	// Inequality operator
	//==========================================================================
	template <class T>
	inline bool operator!=(const Vector3<T>& left, const Vector3<T>& right)
	{
		return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
	}

	//==========================================================================
	// Equality operator
	//==========================================================================
	template <class T>
	inline bool operator==(const Vector3<T>& left, const Vector3<T>& right)
	{
		return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
	}

	typedef Vector3<int> Vector3i;
	typedef Vector3<unsigned int> Vector3u;
	typedef Vector3<float> Vector3f;
	typedef Vector3<double> Vector3d;
}