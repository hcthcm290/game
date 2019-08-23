#pragma once
#include "Surface.h"
#include "Graphics.h"
#include <string>

class world
{
private:
	Surface map;
	int width, height;

public:
	world(std::string filename);
	void Draw(Graphics& gfx, RectI clip);

};
