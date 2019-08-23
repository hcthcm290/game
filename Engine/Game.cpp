/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include "Graphics.h"


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	mario("mario.bmp", Vec2(65,100), 26, 32, 4, 0.11, 200, 0.70),
	maze(),
	bricks("brick.bmp"),
	cWidth(28),
	cHeight(28)
{
	std::string map;
	int mapWidth = 15;
	int mapHeight = 5;
	map += ".......########";
	map += "#....##########";
	map += ".#.............";
	map += ".##############";
	map += "...............";

	for (int i = 0; i < mapWidth * mapHeight; i++)
	{
		if (map[i] == '#')
		{
			bricks.insert(Vec2(i%mapWidth * bricks.width, (mapHeight - i / mapWidth) * bricks.height));
		}
	}

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}


void Game::UpdateModel()
{
	Vec2 vel = { 0.0f,0.0f };
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		vel.y += 1.0f;
	}
	else if(wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		vel.y -= 1.0f;
	}
	
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		vel.x -= 1.0f;
	}
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		vel.x += 1.0f;
	}
	float dt = ft.Mark();
	mario.Update(vel, dt, cam.GetPos(), bricks);
	bricks.Update(dt);
	cam.update(mario.getPos());
}

void Game::ComposeFrame()
{
	bricks.Draw(gfx, cam);
	mario.Draw(gfx, cam);
}