#pragma once
#include "Renderer.h"

class GameObject //falta implementar les altres classes pq heredin d'aquesta.
{
public:
	GameObject();
	~GameObject();
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

