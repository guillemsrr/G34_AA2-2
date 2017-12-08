#pragma once
#include "Scene.h"
#include "Player.h"
class Level1 :
	public Scene
{
public:
	Level1();
	~Level1();
	void EventHandler() override;
	void Update() override;
	void Draw() override;

	Player *p1, *p2;
	int textWidth, textHeight, frameWidth, frameHeight;
	SDL_Rect blockRect, wallRect; //helmetRect, shieldRect, rollerRect;
};

