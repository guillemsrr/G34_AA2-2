#pragma once
#include "Scene.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Constants.h"
#include <SDL_ttf.h>
#include "Bomb.h"

class Player
{
public:
	Player(int num);
	~Player();
	int getPlayerTag();
	SDL_Rect playerPosition, playerRect;
	void bomb(bool explodingLimits[8]);
	Bomb *ptrBomb;
	bool isInPosition();
	bool moving;
	int posX, posY, lives, points;

private:
	int playerTag, textWidth, textHeight, frameWidth, frameHeight, frameTime;
};