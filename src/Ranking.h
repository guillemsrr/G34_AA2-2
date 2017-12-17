#pragma once
#include "GameObject.h"
#include "Scene.h"
class Ranking :
	public Scene
{
public:
	Ranking();
	~Ranking();
	void EventHandler() override;
	void Update() override;
	void Draw() override;
};

