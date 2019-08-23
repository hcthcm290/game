#include "Character.h"
#include <math.h>
#include "Camera.h"

character::character(std::string filename,Vec2 pos, int width, int height, int count, float holdtime, float speedJump , float CoyoteTime )
	:
	sprite(filename),
	pos(pos),
	width(width),
	height(height - 2),
	speedJump(speedJump),
	CoyoteTime(CoyoteTime)
{
	action.emplace_back(Animation(0, 0, width, height, 4, sprite, holdtime, Colors::Magenta));
	action.emplace_back(Animation(0, 0, width, height, 1, sprite, holdtime, Colors::Magenta));
	action.emplace_back(Animation(104, 0, width, height, 1, sprite, holdtime, Colors::Magenta));
}

void character::Update(Vec2 vel, float dt, Vec2 camPos, Brick& bricks)
{
	Rect<float> characterRect = Rect<float>(pos, width, height);
	std::vector<Vec2> BricksPos = bricks.getBrickPosMayColap(characterRect);
	
	auto newPos = pos - Vec2(0.0f, 2.0f);
	if (OnTheGround && vel.y < 0.5f)
	{
		canJump = true;
	}
	if (OnTheGround && vel.y > 0 && canJump)
	{
		newPos.y += speedJump * dt * (CoyoteTime - jmpTime) / CoyoteTime;
		jmpTime += dt;
		Jumping = true;
		OnTheGround = false;
		canJump = false;
		iCur = 2;
	}
	else if (!OnTheGround && Jumping && jmpTime < CoyoteTime && vel.y > 0.0f)
	{
		newPos.y += speedJump * dt * (CoyoteTime - jmpTime) / CoyoteTime;
		jmpTime += dt;
	}
	else if (!OnTheGround)
	{
		newPos.y -= speedJump * dt/1.5;
		Jumping = false;
		jmpTime = 0.0f;
	}
	newPos.x += vel.x * dt * speed;
	OnTheGround = false;
	for (auto brickPos : BricksPos)
	{
		if (newPos.y <= brickPos.y && newPos.y >= brickPos.y - bricks.height ||
			newPos.y - height <= brickPos.y && newPos.y - height > brickPos.y - bricks.height
			)
		{
			if (newPos.x < brickPos.x + bricks.width && newPos.x > brickPos.x)
			{
				if (pos.x >= brickPos.x + bricks.width)
				{
					newPos.x = brickPos.x + bricks.width + 0.5;
				}
			}
			else if (newPos.x + width >= brickPos.x && newPos.x < brickPos.x)
			{
				if (pos.x + width <= brickPos.x)
				{
					newPos.x = brickPos.x - width - 0.5;
				}
			}
		}
		if (newPos.x < brickPos.x + bricks.width && newPos.x > brickPos.x ||
			newPos.x + width > brickPos.x && newPos.x < brickPos.x
			)
		{
			if (newPos.y > brickPos.y - bricks.height && newPos.y < brickPos.y)
			{
				newPos.y = brickPos.y - bricks.height - 0.5;
				Jumping = false;
				bricks.destroy(brickPos);
			}
			else if (newPos.y - height < brickPos.y && newPos.y > brickPos.y)
			{
				newPos.y = brickPos.y + height + 0.5;
				OnTheGround = true;
				iCur = 1;
			}
		}
	}
	pos = newPos + Vec2(0.0f, 2.0f);

	if (iCur == 1 && vel.x != 0)
	{
		iCur = 0;
	}

	action[iCur].Update(dt);
	
	if (vel.x < 0)
	{
		reverse = true;
	}
	else if (vel.x > 0)
	{
		reverse = false;
	}
}

void character::Draw(Graphics& gfx, Camera& cam)
{
	if (reverse)
	{
		action[iCur].DrawR(Vei2(pos.x - cam.GetPos().x, gfx.ScreenHeight - (pos.y - cam.GetPos().y)), gfx);
	}
	else
	{
		action[iCur].Draw(Vei2(pos.x - cam.GetPos().x, gfx.ScreenHeight - (pos.y - cam.GetPos().y)), gfx);
	}
}
