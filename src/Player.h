#pragma once
#include "Scene.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Constants.h"
#include <SDL_ttf.h>

class Player
{
public:
	Player(int num);
	~Player();
	int getPlayerTag();
	SDL_Rect PlayerPosition, PlayerRect;
	Vector2 getFrameStats();

private:
	int points, playerTag, textWidth, textHeight, frameWidth, frameHeight, frameTime;
};