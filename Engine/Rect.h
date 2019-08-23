#pragma once
#include "Vec.h"

template<typename T>
class Rect
{
public:
	Rect() = default;
	Rect(T left_in, T right_in, T top_in, T bottom_in)
		:
		left(left_in),
		right(right_in),
		top(top_in),
		bottom(bottom_in)
	{
	}

	Rect(const Vei2& topLeft, const Vei2& bottomRight)
		:
		Rect(topLeft.x, bottomRight.x, topLeft.y, bottomRight.y)
	{
	}

	Rect(const Vei2& topLeft, int width, int height)
		:
		Rect(topLeft, topLeft + Vei2(width, -height))
	{
	}

	bool IsOverlappingWith(const Rect& other) const
	{
		return right > other.left && left < other.right
			&& bottom > other.top && top < other.bottom;
	}

	bool IsContainedBy(const Rect& other) const
	{
		return left >= other.left && right <= other.right &&
			top >= other.top && bottom <= other.bottom;
	}

	bool Contains(const Vei2& point) const
	{
		return point.x >= left && point.x < right && point.y >= top && point.y < bottom;
	}

	Rect<T> FromCenter(const Vei2& center, T halfWidth, T halfHeight)
	{
		const Vei2 half(halfWidth, halfHeight);
		return Rect(center - half, center + half);
	}

	Rect<T> GetExpanded(T offset) const
	{
		return Rect(left - offset, right + offset, top - offset, bottom + offset);
	}

	Vei2 Rect::GetCenter() const
	{
		return Vei2((left + right) / 2, (top + bottom) / 2);
	}

public:
	T left;
	T right;
	T top;
	T bottom;
};

typedef Rect<int> RectI;