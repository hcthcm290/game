#pragma once

template<typename T>
class _Vec
{
public:
	T x;
	T y;
public:
	_Vec::_Vec(T x_in, T y_in)
		:
		x(x_in),
		y(y_in)
	{
	}

	template<typename P>
	_Vec(const _Vec<P>& temp)
		:
		_Vec((T)temp.x,(T)temp.y)
	{}

	_Vec _Vec::operator+(const _Vec& rhs) const
	{
		return _Vec(x + rhs.x, y + rhs.y);
	}

	_Vec& _Vec::operator+=(const _Vec& rhs)
	{
		return *this = *this + rhs;
	}

	_Vec _Vec::operator*(T rhs) const
	{
		return _Vec(x * rhs, y * rhs);
	}

	_Vec& _Vec::operator*=(T rhs)
	{
		return *this = *this * rhs/1;
	}

	_Vec _Vec::operator-(const _Vec& rhs) const
	{
		return _Vec(x - rhs.x, y - rhs.y);
	}

	_Vec& _Vec::operator-=(const _Vec& rhs)
	{
		return *this = *this - rhs;
	}

	_Vec _Vec::operator/(T rhs) const
	{
		return _Vec(x / rhs, y / rhs);
	}

	_Vec& _Vec::operator/=(T rhs)
	{
		return *this = *this / rhs;
	}

	friend bool operator==(_Vec<T> lhs, _Vec<T> rhs)
	{
		return lhs.x == rhs.x && lhs.y == rhs.y;
	}
};

typedef _Vec<int> Vei2;
typedef _Vec<float> Vec2;