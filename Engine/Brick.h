#pragma once
#include "Surface.h"
#include "Vec.h"
#include <vector>
#include "Camera.h"
#include "Graphics.h"
#include "Rect.h"
#include <algorithm>

class Brick
{
private:
	class BrokenBrick
	{
	private:
		//Surface s;
		int width, height;
		std::vector<float> totalTime;
		std::vector<Vec2> pos;
	public:
		void Draw(Graphics& gfx)
		{
			for (int i = 0; i < pos.size(); i++)
			{
				gfx.DrawRect(pos[i] - Vec2(Min(3.0f, totalTime[i])*2.0f, 0), 10, 10, Colors::Red);
				gfx.DrawRect(pos[i] + Vec2(width, 0) + Vec2(Min(3.0f, totalTime[i])*2.0f, 0), 10, 10, Colors::Red);
			}
		}
		void Update(float dt)
		{
			for (int i = 0; i < pos.size(); i++)
			{
				totalTime[i] += dt;
				pos[i].y -= 100 * dt;
			}
		}
		BrokenBrick(int width, int height)
			:
			width(width),
			height(height)
		{}
		void add(Vec2 newPos)
		{
			pos.push_back(newPos);
			totalTime.push_back(0.0f);
		}

	private:
		float Min(float a, float b)
		{
			if (a < b)
			{
				return a;
			}
			return b;
		}
	};

public:
	Brick(std::string filename)
		:
		s(filename),
		BrokenBricks(s.GetWidth(), s.GetHeight())
	{
		width = s.GetWidth();
		height = s.GetHeight();
	}

	void insert(Vec2 pos_in)
	{
		pos.push_back(pos_in);
	}

	void Draw(Graphics& gfx, const Camera &cam)
	{
		Vec2 CamPos = cam.GetPos();

		for (auto i : pos)
		{
			Vec2 position = Vec2(i.x - CamPos.x, Graphics::ScreenHeight - (i.y - CamPos.y));
			gfx.DrawSprite(i.x - CamPos.x,Graphics::ScreenHeight - (i.y - CamPos.y), RectI(0, width, 0, height), gfx.GetScreenRect(), s, Colors::Magenta);
		}
		BrokenBricks.Draw(gfx);
	}

	std::vector<Vec2> getBrickPosMayColap(Rect<float> characterRect)
	{
		float Xmin = (int)(characterRect.left   - 2*width);
		float Ymin = (int)(characterRect.bottom - 2*height);
		float Xmax = (int)(characterRect.right  + 2*width);
		float Ymax = (int)(characterRect.top	+ 2*height);
		std::vector<Vec2> out;
		for (int i = 0; i < pos.size(); i++)
		{
			if (pos[i].x >= Xmin && pos[i].x <= Xmax && pos[i].y >= Ymin && pos[i].y <= Ymax)
			{
				out.push_back(pos[i]);
			}
		}
		return out;
	}

	void Update(float dt)
	{
		BrokenBricks.Update(dt);
	}

	void destroy(Vec2 location)
	{
		for (int i = 0; i < pos.size(); i++)
		{
			if (pos[i] == location)
			{
				pos.erase(pos.begin() + i);
			}
		}
		BrokenBricks.add(location);
	}

private:
	Surface s;
	std::vector<Vec2> pos;
	BrokenBrick BrokenBricks;
	bool broken = false;

public:
	int width;
	int height;
};
