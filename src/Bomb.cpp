#include "Bomb.h"

Bomb::Bomb(SDL_Rect pos): bombPosition{pos}, explode{false}, end{false}
{
	Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "items.png");
	textWidth = Renderer::Instance()->GetTextureSize(ITEMS).x;
	textHeight = Renderer::Instance()->GetTextureSize(ITEMS).y;
	frameWidth = textWidth / 3;
	frameHeight = textHeight / 2;
	bombRect = { 0,frameHeight,frameWidth,frameHeight };

	Renderer::Instance()->LoadTexture(EXPLOSIONS, PATH_IMG + "explosion.png");
	textWidth = Renderer::Instance()->GetTextureSize(EXPLOSIONS).x;
	textHeight = Renderer::Instance()->GetTextureSize(EXPLOSIONS).y;
	frameWidth = textWidth / 4;
	frameHeight = textHeight / 7;
	explosionRect = { 0,0,frameWidth,frameHeight };

	//comencem el temps:
	//start_time.now();
	start = time(0);
}

Bomb::~Bomb()
{
}
void Bomb :: Update()
{
	if ((difftime(time(0),start)>=3))
	{
		if (!explode) 
		{
			explode = true;
			start = time(0);
		}
		else
		{
			end = true;
		}
	}
	else if (explode)
	{
		frameTime++;
		if (SCREEN_FPS / frameTime <= 3)
		{
			frameTime = 0;
			explosionRect.x += explosionRect.w;
			if (explosionRect.x >= textWidth)
				explosionRect.x = 0;
		}
	}
}

void Bomb::Draw()
{
	//Renderer::Instance()->Clear();
	if(!explode) Renderer::Instance()->PushSprite(ITEMS, bombRect, bombPosition);
	else Renderer::Instance()->PushSprite(EXPLOSIONS, explosionRect, bombPosition);

	Renderer::Instance()->Render();
}

void Bomb::explodingLimits()
{

}
