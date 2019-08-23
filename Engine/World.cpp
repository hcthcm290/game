#include "World.h"

world::world(std::string filename)
	:
	map(filename)
{
	width = map.GetWidth();
	height = map.GetHeight();
}

void world::Draw(Graphics & gfx, RectI clip)
{
	gfx.DrawSprite(0, 0, clip, gfx.GetScreenRect(), map, Colors::Magenta);
}
