#pragma once
#include "Vec.h"
#include "Graphics.h"

class Camera
{
public:
	Vec2 GetPos() const
	{
		return pos;
	}

	void Translate(Vec2 pos_in)
	{
		pos += pos_in;
	}

	void update(Vec2 characterPos)
	{
		if (characterPos.x - pos.x > Graphics::ScreenWidth / 2)
		{
			pos.x += characterPos.x - pos.x - Graphics::ScreenWidth/2;
		}
	}
private:
	Vec2 pos = {0.0f, 0.0f};
	float camSpeed = 100.0f;
};
