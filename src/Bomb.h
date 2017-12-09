#pragma once
#include "SDL.h"
#include "Renderer.h"
#include <time.h>
#include <chrono>
#include <iostream>

class Bomb
{
public:
	Bomb(SDL_Rect pos);
	~Bomb();
	bool end;
	void Update();
	void Draw();

private:
	int textWidth, textHeight, frameWidth, frameHeight, frameTime;
	SDL_Rect bombRect, bombPosition, explosionRect;
	bool explode;
	void explodingLimits();

	//TIME:
	//std::chrono::steady_clock start_time;
	//std::chrono::steady_clock current_time;
	time_t start;


};

