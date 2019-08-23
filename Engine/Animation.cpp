#include "Animation.h"

Animation::Animation(int x, int y, int width, int height, int count, const Surface& sprite, float holdtime, Color chroma)
	:
	chroma(chroma),
	holdTime(holdtime),
	sprite(sprite)
{
	for (int i = 0; i < count; i++)
	{
		frames.emplace_back(x + i * width, x + (i + 1) * width, y, y + height); 
	}
}

void Animation::Draw(const Vei2& pos, Graphics& gfx)
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], gfx.GetScreenRect(), sprite, chroma);
}

void Animation::Draw(const Vei2& pos, Graphics& gfx, const RectI& clip)
{
	gfx.DrawSprite(pos.x, pos.y, frames[iCurFrame], clip, sprite, chroma);
}

void Animation::DrawR(const Vei2 & pos, Graphics & gfx)
{
	gfx.DrawSpriteR(pos.x, pos.y, frames[iCurFrame], gfx.GetScreenRect(), sprite, chroma);
}

void Animation::Update(float dt)
{
	CurFrametime += dt;
	while (CurFrametime >= holdTime)
	{
		Advance();
		CurFrametime -= holdTime;
	}
}

void Animation::Advance()
{
	if (++iCurFrame >= frames.size())
	{
		iCurFrame = 0;
	}
}
