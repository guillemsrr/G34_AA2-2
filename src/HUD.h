#pragma once
#include "Player.h"
#include <time.h>

class HUD
{
public:
	HUD(Player *p1, Player *p2);
	~HUD();
	void Update();
	void Draw();

	int timer;
private:
	Player *player1;
	Player *player2;

	//TIME:
	time_t start;
};

