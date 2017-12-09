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
	int keyDown, step;
	SDL_Rect blockRect, wallRect; //helmetRect, shieldRect, rollerRect;
	std::list<SDL_Rect> blockList;
	bool exit;
	//bombs:
	Bomb* p1Bomb;
	Bomb* p2Bomb;

	static constexpr SDL_Rect limitUp = { 0,static_cast<int>(SCREEN_HEIGHT / 15) * 3,SCREEN_WIDTH,0 };
	static constexpr SDL_Rect limitLeft = { static_cast<int>(SCREEN_WIDTH / 15),0,0,SCREEN_HEIGHT};
	static constexpr SDL_Rect limitDown = { 0,static_cast<int>(SCREEN_HEIGHT - SCREEN_HEIGHT / 15),SCREEN_WIDTH, 0 };
	static constexpr SDL_Rect limitRight = { static_cast<int>(SCREEN_WIDTH - SCREEN_WIDTH / 15),0,0,SCREEN_HEIGHT };
};

