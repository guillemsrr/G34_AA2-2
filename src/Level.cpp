#include "Level.h"

Level::Level(int num) : exit{ false }, lvlNumber{ num }, frameTime{ 0 }, keyDown{ 0 }, p1{ new Player(1) }, p2{ new Player(2) }, step{ 16 }, p1Bomb{nullptr}, p2Bomb{nullptr}
{
	m_sceneState= Scene::SceneState::Running;
	Renderer::Instance()->LoadTexture(LEVEL_BG, PATH_IMG + "bgGame.jpg");
	Renderer::Instance()->LoadTexture(ITEMS, PATH_IMG + "items.png");

	textWidth = Renderer::Instance()->GetTextureSize(ITEMS).x;
	textHeight = Renderer::Instance()->GetTextureSize(ITEMS).y;
	frameWidth = textWidth / 6;
	frameHeight = textHeight / 2;

	blockRect = { 0,0, frameWidth,frameHeight };
	wallRect = { frameWidth,0,frameWidth,frameHeight };
}

Level::~Level()
{
}

void Level::EventHandler()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:	
			exit = true;	 
			break;
		case SDL_KEYDOWN:	
			if (event.key.keysym.sym == SDLK_ESCAPE) exit = true; 
			keyDown = event.key.keysym.sym; 
			break;
		case SDL_KEYUP:
			keyDown = NULL;//correcte?
		default:;
		}
	}
}

void Level::Update()
{
	if (exit) m_sceneState = Scene::SceneState::Exit;
	frameTime++;
	if (SCREEN_FPS / frameTime <= SPEED)
	{
		if (keyDown == SDLK_w)
		{
			bool stay = false;
			frameTime = 0;
			p1->PlayerRect.y = 0;
			p1->PlayerRect.x += p1->PlayerRect.w;
			if (p1->PlayerRect.x >= p1->PlayerRect.w * 2)
				p1->PlayerRect.x = 0;
			/*
			for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
			{
				if (isCollisioning(p1->PlayerPosition, *it))
				{
					stay = true;
				}
			}
			*/
			if(!stay) p1->PlayerPosition.y -= step;

		}
		else if (keyDown == SDLK_a)
		{
			bool stay = false;
			frameTime = 0;
			p1->PlayerRect.y = p1->PlayerRect.h;
			p1->PlayerRect.x += p1->PlayerRect.w;
			if (p1->PlayerRect.x >= p1->PlayerRect.w * 3)
				p1->PlayerRect.x = 0;
			/*
			for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
			{
				if (isCollisioning(p1->PlayerPosition, *it))
				{
					stay = true;
				}
			}
			*/
			if(!stay) p1->PlayerPosition.x -= step;
		}
		else if (keyDown == SDLK_s)
		{
			bool stay = false;
			frameTime = 0;
			p1->PlayerRect.y = p1->PlayerRect.h * 2;
			p1->PlayerRect.x += p1->PlayerRect.w;
			if (p1->PlayerRect.x >= p1->PlayerRect.w * 3)
				p1->PlayerRect.x = 0;
			/*
			for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
			{
				if (isCollisioning(p1->PlayerPosition, *it))
				{
					stay = true;
				}
			}
			*/
			if (!stay) p1->PlayerPosition.y += step;
		}

		else if (keyDown == SDLK_d)
		{
			bool stay = false;
			frameTime = 0;
			p1->PlayerRect.y = p1->PlayerRect.h * 3;
			p1->PlayerRect.x += p1->PlayerRect.w;
			if (p1->PlayerRect.x >= p1->PlayerRect.w* 3)
				p1->PlayerRect.x = 0;
			/*
			for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
			{
				if (isCollisioning(p1->PlayerPosition, *it))
				{
					stay = true;
				}
			}
			*/
			if (!stay) p1->PlayerPosition.x += step;
		}
		if (keyDown == SDLK_UP)
		{
			bool stay = false;
			frameTime = 0;
			p2->PlayerRect.y = 0;
			p2->PlayerRect.x += p2->PlayerRect.w;
			if (p2->PlayerRect.x >= p2->PlayerRect.w * 2)
				p2->PlayerRect.x = 0;
			/*
			for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
			{
				if (isCollisioning(p2->PlayerPosition, *it))
				{
					stay = true;
				}
			}
			*/
			if (!stay) p2->PlayerPosition.y -= step;
		}
		else if (keyDown == SDLK_LEFT)
		{
			bool stay = false;
			frameTime = 0;
			p2->PlayerRect.y = p2->PlayerRect.h;
			p2->PlayerRect.x += p2->PlayerRect.w;
			if (p2->PlayerRect.x >= p2->PlayerRect.w* 3)
				p2->PlayerRect.x = 0;
			/*
			for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
			{
				if (isCollisioning(p2->PlayerPosition, *it))
				{
					stay = true;
				}
			}
			*/
			if (!stay) p2->PlayerPosition.x -= step;
		}
		else if (keyDown == SDLK_DOWN)
		{
			bool stay = false;
			frameTime = 0;
			p2->PlayerRect.y = p2->PlayerRect.h* 2;
			p2->PlayerRect.x += p2->PlayerRect.w;
			if (p2->PlayerRect.x >= p2->PlayerRect.w * 3)
				p2->PlayerRect.x = 0;
			/*
			for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
			{
				if (isCollisioning(p2->PlayerPosition, *it))
				{
					stay = true;
				}
			}
			*/
			if (!stay) p2->PlayerPosition.y += step;
		}
		else if (keyDown == SDLK_RIGHT)
		{
			bool stay = false;
			frameTime = 0;
			p2->PlayerRect.y = p2->PlayerRect.h* 3;
			p2->PlayerRect.x += p2->PlayerRect.w;
			if (p2->PlayerRect.x >= p2->PlayerRect.w * 3)
				p2->PlayerRect.x = 0;
			/*
			for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
			{
				if (isCollisioning(p2->PlayerPosition, *it))
				{
					stay = true;
				}
			}
			*/
			if (!stay) p2->PlayerPosition.x += step;
		}
		if (keyDown == SDLK_SPACE)
		{
			if(p1Bomb==nullptr) p1Bomb=p1->bomb();
		}
		if (keyDown == SDLK_RCTRL)
		{
			if(p2Bomb==nullptr)  p2Bomb=p2->bomb();
		}
	}

	//Map Limits:
	/*
	if (isCollisioning(p1->PlayerRect, limitUp)) p1->PlayerPosition.y = limitUp.y;
	if (isCollisioning(p1->PlayerRect, limitLeft)) p1->PlayerPosition.x = limitLeft.x;
	if (isCollisioning(p1->PlayerRect, limitDown)) p1->PlayerPosition.y = limitDown.y;
	if (isCollisioning(p1->PlayerRect, limitRight)) p1->PlayerPosition.x = limitRight.x;

	if (isCollisioning(p2->PlayerRect, limitUp)) p2->PlayerPosition.y = limitUp.y;
	if (isCollisioning(p2->PlayerRect, limitLeft)) p2->PlayerPosition.x = limitLeft.x;
	if (isCollisioning(p2->PlayerRect, limitDown)) p2->PlayerPosition.y = limitDown.y;
	if (isCollisioning(p2->PlayerRect, limitRight)) p2->PlayerPosition.x = limitRight.x;
	*/
	if (p1->PlayerPosition.x >= SCREEN_WIDTH - SCREEN_WIDTH/15*2) p1->PlayerPosition.x = SCREEN_WIDTH - SCREEN_WIDTH / 15*2;
	if (p1->PlayerPosition.x <= SCREEN_WIDTH / 15) p1->PlayerPosition.x = SCREEN_WIDTH / 15;
	if (p1->PlayerPosition.y <= (SCREEN_HEIGHT/15)*3) p1->PlayerPosition.y = (SCREEN_HEIGHT / 15) * 3;
	if (p1->PlayerPosition.y >= SCREEN_HEIGHT - (SCREEN_HEIGHT / 15)*2) p1->PlayerPosition.y = SCREEN_HEIGHT - (SCREEN_HEIGHT / 15) * 2;

	if (p2->PlayerPosition.x >= SCREEN_WIDTH - SCREEN_WIDTH / 15*2) p2->PlayerPosition.x = SCREEN_WIDTH - SCREEN_WIDTH / 15*2;
	if (p2->PlayerPosition.x <= SCREEN_WIDTH / 15) p2->PlayerPosition.x = SCREEN_WIDTH / 15;
	if (p2->PlayerPosition.y <= (SCREEN_HEIGHT / 15) * 3) p2->PlayerPosition.y = (SCREEN_HEIGHT / 15) * 3;
	if (p2->PlayerPosition.y >= SCREEN_HEIGHT - (SCREEN_HEIGHT / 15) * 2) p2->PlayerPosition.y = SCREEN_HEIGHT - (SCREEN_HEIGHT / 15) * 2;

	//Blocks Collisions:
	
	for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
	{
		if (isCollisioning(p1->PlayerPosition, *it))
		{
			if (keyDown == SDLK_w)
			{
				p1->PlayerPosition.y += step;

			}
			else if (keyDown == SDLK_a)
			{
				p1->PlayerPosition.x += step;

			}
			else if (keyDown == SDLK_s)
			{
				p1->PlayerPosition.y -= step;
			}

			else if (keyDown == SDLK_d)
			{
				p1->PlayerPosition.x -= step;
			}
		}
		if (isCollisioning(p2->PlayerPosition, *it))
		{
			if (keyDown == SDLK_UP)
			{
				p2->PlayerPosition.y += step;
			}
			else if (keyDown == SDLK_LEFT)
			{
				p2->PlayerPosition.x += step;
			}
			else if (keyDown == SDLK_DOWN)
			{
				p2->PlayerPosition.y -= step;
			}
			else if (keyDown == SDLK_RIGHT)
			{
				p2->PlayerPosition.x -= step;
			}
		}
	}
	
	

	//Bombs:
	if (p1Bomb != nullptr)
	{
		if (!p1Bomb->end)
		{
			p1Bomb->Update();
		}
		if (p1Bomb->end)
		{
			delete p1Bomb;
			p1Bomb = nullptr;
		}
	}
	
	if (p2Bomb != nullptr)
	{
		if (!p2Bomb->end)
		{
			p2Bomb->Update();
		}
		if (p2Bomb->end)
		{
			delete p2Bomb;
			p2Bomb = nullptr;
		}
	}
}

void Level::Draw()
{
	Renderer::Instance()->Clear();

	//Background
	Renderer::Instance()->PushImage(LEVEL_BG, { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT });

	//Blocks:
	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			SDL_Rect blockPosition = { (SCREEN_WIDTH / 15)* (2 * i), (SCREEN_HEIGHT / 15) *(2 * j + 2), 48,48 };
			Renderer::Instance()->PushSprite(ITEMS, blockRect, blockPosition);
			//blockPosition.x += 10;
			//blockPosition.y += 10;
			//blockPosition.w -= 10;
			//blockPosition.h -= 10,
			blockList.push_back(blockPosition);
		}
	}

	//Bombs:
	if (p1Bomb != nullptr && !p1Bomb->end)
	{
		p1Bomb->Draw();
	}
	if (p2Bomb != nullptr && !p2Bomb->end)
	{
		p2Bomb->Draw();
	}

	//Animated Sprite
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, p1->PlayerRect, p1->PlayerPosition);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, p2->PlayerRect, p2->PlayerPosition);
	
	Renderer::Instance()->Render();
}
