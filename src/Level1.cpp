#include "Level1.h"

Level1::Level1()
{
	m_sceneState= Scene::SceneState::Running;
	Renderer::Instance()->LoadTexture(LEVEL1_BG, PATH_IMG + "bgGame.jpg");
	Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "items.png");


	textWidth = Renderer::Instance()->GetTextureSize(ITEMS).x;
	textHeight = Renderer::Instance()->GetTextureSize(ITEMS).y;
	frameWidth = textWidth / 6;
	frameHeight = textHeight / 2;

	blockRect = { 0,0, frameWidth,frameHeight };
	wallRect = { frameWidth,0,frameWidth,frameHeight };
	    

}


Level1::~Level1()
{
}

void Level1::EventHandler()
{
}

void Level1::Update()
{
}

void Level1::Draw()
{
	//Background
	Renderer::Instance()->Clear();
	Renderer::Instance()->PushImage(LEVEL1_BG, { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT });
	//Animated Sprite
	//Renderer::Instance()->PushSprite(PLAYER_SPRITE, p1->PlayerRect, p1->PlayerPosition);
	//Renderer::Instance()->PushSprite(PLAYER_SPRITE, p2->PlayerRect, p2->PlayerPosition);

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			Renderer::Instance()->PushSprite(ITEMS, blockRect, {SCREEN_WIDTH / 7 * i, SCREEN_HEIGHT / 6 * j, 48,48 });
		}
	}
	

	Renderer::Instance()->Render();
}
