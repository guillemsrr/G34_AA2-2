#pragma once
#include "Scene.h"
class Level1 :
	public Scene
{
public:
	Level1();
	~Level1();
	void EventHandler() override;
	void Update() override;
	void Draw() override;
};

