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
	SDL_Rect PlayerPosition, PlayerRect;
	void bomb();

private:
	int points, playerTag, textWidth, textHeight, frameWidth, frameHeight, frameTime;
	Bomb *ptrBomb;
};