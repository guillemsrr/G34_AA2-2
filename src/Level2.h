#pragma once
#include "Scene.h"
class Level2 :
	public Scene
{
public:
	Level2();
	~Level2();
	void EventHandler() override;
	void Update() override;
	void Draw() override;
};

