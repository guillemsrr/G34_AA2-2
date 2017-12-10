#pragma once
#include "Scene.h"
#include "Player.h"
#include <list>
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
	void checkDamage(Bomb *b);
};

