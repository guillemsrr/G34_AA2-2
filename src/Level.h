#pragma once
#include "Scene.h"
#include "Player.h"
#include <list>
#include <vector>
#include "HUD.h"
#include "Wall.h"
#include "Grid.h"

#define SPEED 10

class Level :
	public Scene
{
public:
	Level(int num);
	~Level();
	void EventHandler() override;
	void Update() override;
	void Draw() override;

private:
	Player *p1, *p2;
	int lvlNumber, textWidth, textHeight, frameWidth, frameHeight, frameTime;
	//control:
	std::string grid[13][11];
	int keyDown, step;
	SDL_Rect blockRect, wallRect; //helmetRect, shieldRect, rollerRect;
	std::list<SDL_Rect> blockList;
	bool exit;
	//explosions:
	bool explosionLimits[8];
	void setExplosionLimits(Player *p);
	void restartExplosionLimits();
	void checkDamage(Player *p);
	void changePlayerLocation(Player *p);
	HUD *m_hud;
	Wall *w;
	std::list<Wall*> wallList;
	void detectWall(int x, int y);
};

