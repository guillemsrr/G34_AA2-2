#pragma once
#include "SDL.h"
#include "Renderer.h"
#include <time.h>
#include <chrono>
#include <iostream>

class Bomb
{
public:
	Bomb(SDL_Rect pos, bool explosionLimits[8]);
	~Bomb();
	bool end, explode;
	void Update();
	void Draw();
	int posX, posY;

private:
	int textWidth, textHeight, frameWidth, frameHeight, frameTime;
	SDL_Rect bombRect, bombPosition, centralExplosionRect, explosion0Rect, explosion1Rect, explosion2Rect, explosion3Rect, explosion4Rect, explosion5Rect, explosion6Rect, explosion7Rect;
	bool explodingLimits[8];

	//TIME:
	time_t start;
};

