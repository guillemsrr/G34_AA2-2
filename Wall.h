#pragma once
#include "GameObject.h"
class Wall :
	public GameObject
{
public:
	Wall(int x, int y);
	~Wall();

	void Update() override;
	void Draw() override;

	void destroyWall();
	
	int posI,posJ;
	int textWidth, textHeight, frameWidth, frameHeight;
	SDL_Rect wallRect, wallPosition;

	bool destroy;
private:
	void createPowerUp();
	bool powerUpMode;
};

