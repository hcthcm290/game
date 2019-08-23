#pragma once
#include "Surface.h"
#include "Graphics.h"
#include "Rect.h"
#include "Vec.h"
#include <vector>

class Animation
{

public:
	Animation(int x, int y, int width, int height, int count, const Surface& sprite, float holdtime, Color choroma);
	void Draw(const Vei2& pos, Graphics& gfx);
	void Draw(const Vei2& pos, Graphics& gfx, const RectI& clip);
	void DrawR(const Vei2& pos, Graphics& gfx);
	void Update(float dt);
private:
	void Advance();
	
private:
	Color chroma;
	const Surface& sprite;
	std::vector<RectI> frames;
	int iCurFrame = 0;
	float holdTime;
	float CurFrametime = 0.0f;
};