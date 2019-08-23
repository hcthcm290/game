#pragma once

#include "Surface.h"
#include "Animation.h"
#include "Vec.h"
#include "Vec.h"
#include "string"
#include <vector>
#include "Colors.h"
#include "Graphics.h"
#include "FrameTimer.h"
#include "Camera.h"
#include "Brick.h"

class character
{
public:
	character(std::string filename,Vec2 pos, int width, int height, int count, float holdtime, float speedJump , float CoyoteTime );
	void Update(Vec2 vec, float dt, Vec2 camPos, Brick& brick);
	void Draw(Graphics& gfx, Camera& cam);
	Vec2 getPos()
	{
		return pos;
	}

private:
	
private:
	Surface sprite;

	int width, height;
	bool reverse = false;
	float speedJump;
	float jmpTime = 0;
	float CoyoteTime;
	std::vector<Animation> action;
	Vec2 pos;
	float speed = 70;
	int iCur = 0;

	bool canJump = false;
	bool Jumping = false;
	bool OnTheGround = false;
	bool Moving = false;
};
