#include "Level.h"

Level::Level(int num) : exit{ false }, lvlNumber{ num }, frameTime{ 0 }, keyDown{ 0 }, p1{ new Player(1) }, p2{ new Player(2) }, step{ 16 }, m_hud{new HUD(p1, p2)}
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

	//start the grid:
	for (int i = 0; i <= 12; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (i == 0 && j == 5) 
			{
				grid[i][j] = "player1";
				p1->posX = i;
				p1->posY = j;
			} 
			else if (i == 12 && j == 5)
			{
				grid[i][j] = "player2";
				p2->posX = i;
				p2->posY = j;
			}
			else grid[i][j] = "empty";
		}
	}
	restartExplosionLimits();
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
			if(!p1->moving && !p2->moving) keyDown = event.key.keysym.sym; 
			break;
		default:;
		}
	}
}

void Level::Update()
{
	if (exit) m_sceneState = Scene::SceneState::Exit;
	if(m_hud->timer<=0) m_sceneState = Scene::SceneState::GoToRanking;

	//Movement:
	frameTime++;
	if (SCREEN_FPS / frameTime <= SPEED)
	{
		if (keyDown == SDLK_w)
		{
			p1->moving = true;
			frameTime = 0;
			p1->playerRect.y = 0;
			p1->playerRect.x += p1->playerRect.w;
			if (p1->playerRect.x >= p1->playerRect.w * 2)
				p1->playerRect.x = 0;
			p1->playerPosition.y -= step;
			if (p1->isInPosition())
			{
				grid[p1->posX][p1->posY] = "empty";
				p1->posY--;
				grid[p1->posX][p1->posY] = "player1";
			}
		}
		else if (keyDown == SDLK_a)
		{
			p1->moving = true;
			frameTime = 0;
			p1->playerRect.y = p1->playerRect.h;
			p1->playerRect.x += p1->playerRect.w;
			if (p1->playerRect.x >= p1->playerRect.w * 3)
				p1->playerRect.x = 0;
			p1->playerPosition.x -= step;
			if (p1->isInPosition())
			{
				grid[p1->posX][p1->posY] = "empty";
				p1->posX--;
				grid[p1->posX][p1->posY] = "player1";
			}
		}
		else if (keyDown == SDLK_s)
		{
			p1->moving = true;
			frameTime = 0;
			p1->playerRect.y = p1->playerRect.h * 2;
			p1->playerRect.x += p1->playerRect.w;
			if (p1->playerRect.x >= p1->playerRect.w * 3)
				p1->playerRect.x = 0;
			p1->playerPosition.y += step;
			if (p1->isInPosition())
			{
				grid[p1->posX][p1->posY] = "empty";
				p1->posY++;
				grid[p1->posX][p1->posY] = "player1";
			}
		}

		else if (keyDown == SDLK_d)
		{
			p1->moving = true;
			frameTime = 0;
			p1->playerRect.y = p1->playerRect.h * 3;
			p1->playerRect.x += p1->playerRect.w;
			if (p1->playerRect.x >= p1->playerRect.w* 3)
				p1->playerRect.x = 0;
			p1->playerPosition.x += step;
			if (p1->isInPosition())
			{
				grid[p1->posX][p1->posY] = "empty";
				p1->posX++;
				grid[p1->posX][p1->posY] = "player1";
			}
		}
		if (keyDown == SDLK_UP)
		{
			p2->moving = true;
			frameTime = 0;
			p2->playerRect.y = 0;
			p2->playerRect.x += p2->playerRect.w;
			if (p2->playerRect.x >= p2->playerRect.w * 2)
				p2->playerRect.x = 0;
			p2->playerPosition.y -= step;
			if (p2->isInPosition())
			{
				grid[p2->posX][p2->posY] = "empty";
				p1->posX--;
				grid[p2->posX][p2->posY] = "player2";
			}
		}
		else if (keyDown == SDLK_LEFT)
		{
			p2->moving = true;
			frameTime = 0;
			p2->playerRect.y = p2->playerRect.h;
			p2->playerRect.x += p2->playerRect.w;
			if (p2->playerRect.x >= p2->playerRect.w* 3)
				p2->playerRect.x = 0;
			p2->playerPosition.x -= step;
			if (p2->isInPosition())
			{
				grid[p2->posX][p2->posY] = "empty";
				p1->posX--;
				grid[p2->posX][p2->posY] = "player2";
			}
		}
		else if (keyDown == SDLK_DOWN)
		{
			p2->moving = true;
			frameTime = 0;
			p2->playerRect.y = p2->playerRect.h* 2;
			p2->playerRect.x += p2->playerRect.w;
			if (p2->playerRect.x >= p2->playerRect.w * 3)
				p2->playerRect.x = 0;
			p2->playerPosition.y += step;
			if (p2->isInPosition())
			{
				grid[p2->posX][p2->posY] = "empty";
				p1->posY++;
				grid[p2->posX][p2->posY] = "player2";
			}
		}
		else if (keyDown == SDLK_RIGHT)
		{
			p2->moving = true;
			frameTime = 0;
			p2->playerRect.y = p2->playerRect.h* 3;
			p2->playerRect.x += p2->playerRect.w;
			if (p2->playerRect.x >= p2->playerRect.w * 3)
				p2->playerRect.x = 0;
			p2->playerPosition.x += step;
			if (p2->isInPosition())
			{
				grid[p2->posX][p2->posY] = "empty";
				p1->posX++;
				grid[p2->posX][p2->posY] = "player2";
			}
		}

		if (keyDown == SDLK_SPACE)
		{
			if (p1->ptrBomb == nullptr)
			{
				setExplosionLimits(p1);
				p1->bomb(explosionLimits);
				restartExplosionLimits();
			}
		}
		if (keyDown == SDLK_RCTRL)
		{
			if (p2->ptrBomb == nullptr)
			{
				setExplosionLimits(p2);
				p2->bomb(explosionLimits);
				restartExplosionLimits();
			}
		}

		if (!p2->moving && p1->isInPosition())
		{
			p1->moving = false;
			keyDown = NULL;
		}

		if (!p1->moving && p2->isInPosition())
		{
			p2->moving = false;
			keyDown = NULL;
		}
	}

	//Map Limits:
	if (p1->playerPosition.x >= SCREEN_WIDTH - SCREEN_WIDTH / 15 * 2)
	{
		p1->playerPosition.x = SCREEN_WIDTH - SCREEN_WIDTH / 15 * 2;
		p1->moving = false;
	}
	if (p1->playerPosition.x < SCREEN_WIDTH / 15)
	{
		p1->playerPosition.x = SCREEN_WIDTH / 15;
		p1->moving = false;
	}
		
	if (p1->playerPosition.y < (SCREEN_HEIGHT - 80) / 13 + 80)
	{
		p1->playerPosition.y = (SCREEN_HEIGHT - 80) / 13 + 80;
		p1->moving = false;
	}
		
	if (p1->playerPosition.y > SCREEN_HEIGHT - ((SCREEN_HEIGHT - 80) / 13 + 80))
	{
		p1->playerPosition.y = SCREEN_HEIGHT - ((SCREEN_HEIGHT - 80) / 13 + 80);
		p1->moving = false;
	}
		

	if (p2->playerPosition.x > SCREEN_WIDTH - SCREEN_WIDTH / 15 * 2)
	{
		p2->playerPosition.x = SCREEN_WIDTH - SCREEN_WIDTH / 15 * 2;
		p2->moving = false;
	}
		
	if (p2->playerPosition.x < SCREEN_WIDTH / 15)
	{
		p2->playerPosition.x = SCREEN_WIDTH / 15;
		p2->moving = false;
	}
	if (p2->playerPosition.y < (SCREEN_HEIGHT - 80) / 13 + 80)
	{
		p2->playerPosition.y = (SCREEN_HEIGHT - 80) / 13 + 80;
		p2->moving = false;
	}
	if (p2->playerPosition.y > SCREEN_HEIGHT - ((SCREEN_HEIGHT - 80) / 13 + 80))
	{
		p2->playerPosition.y = SCREEN_HEIGHT - ((SCREEN_HEIGHT - 80) / 13 + 80);
		p2->moving = false;
	}

	//Blocks Collisions:
	for (std::list<SDL_Rect>::const_iterator it = blockList.cbegin(); it != blockList.cend(); ++it)
	{
		if (isCollisioning(p1->playerPosition, *it))
		{
			if (keyDown == SDLK_w)
			{
				p1->playerPosition.y += step;
				p1->moving = false;

			}
			else if (keyDown == SDLK_a)
			{
				p1->playerPosition.x += step;
				p1->moving = false;
			}
			else if (keyDown == SDLK_s)
			{
				p1->playerPosition.y -= step;
				p1->moving = false;
			}

			else if (keyDown == SDLK_d)
			{
				p1->playerPosition.x -= step;
				p1->moving = false;
			}
		}
		if (isCollisioning(p2->playerPosition, *it))
		{
			if (keyDown == SDLK_UP)
			{
				p2->playerPosition.y += step;
				p2->moving = false;
			}
			else if (keyDown == SDLK_LEFT)
			{
				p2->playerPosition.x += step;
				p2->moving = false;
			}
			else if (keyDown == SDLK_DOWN)
			{
				p2->playerPosition.y -= step;
				p2->moving = false;
			}
			else if (keyDown == SDLK_RIGHT)
			{
				p2->playerPosition.x -= step;
				p2->moving = false;
			}
		}
	}

	//Bombs:
	if (p1->ptrBomb != nullptr)
	{
		if (!p1->ptrBomb->end)
		{
			p1->ptrBomb->Update();
			if (p1->ptrBomb->explode)
			{
				checkDamage(p1);	
			}
		}
		if (p1->ptrBomb->end)
		{
			delete p1->ptrBomb;
			p1->ptrBomb = nullptr;
		}
	}
	
	if (p2->ptrBomb != nullptr)
	{
		if (!p2->ptrBomb->end)
		{
			p2->ptrBomb->Update();
			if (p2->ptrBomb->explode)
			{
				checkDamage(p2);
			}
		}
		if (p2->ptrBomb->end)
		{
			delete p2->ptrBomb;
			p2->ptrBomb = nullptr;
		}
	}

	//HUD:
	m_hud->Update();
}

void Level::Draw()
{
	Renderer::Instance()->Clear();

	//Background
	Renderer::Instance()->PushImage(LEVEL_BG, { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT });

	//Blocks:
	for (int i = 1; i <= 11; i+=2)
	{
		for (int j = 1; j <= 9; j+=2)
		{
			SDL_Rect blockPosition = { static_cast<int>((SCREEN_WIDTH / 15)* (i+1)), static_cast<int>(((SCREEN_HEIGHT - 80) / 13)* (j+1) + 80), 48,48 };
			Renderer::Instance()->PushSprite(ITEMS, blockRect, blockPosition);
			blockList.push_back(blockPosition);
			grid[i][j] = "block";
		}
	}
	//Bombs:
	if (p1->ptrBomb != nullptr && !p1->ptrBomb->end)
	{
		p1->ptrBomb->Draw();
	}
	if (p2->ptrBomb != nullptr && !p2->ptrBomb->end)
	{
		p2->ptrBomb->Draw();
	}

	//Animated Sprite
	Renderer::Instance()->PushSprite(PLAYER1_SPRITE, p1->playerRect, p1->playerPosition);
	Renderer::Instance()->PushSprite(PLAYER2_SPRITE, p2->playerRect, p2->playerPosition);
	
	//HUD:
	m_hud->Draw();

	Renderer::Instance()->Render();
}

void Level::setExplosionLimits(Player *p)
{
	if (p->posY - 2 >= 0 && grid[p->posX][p->posY - 2] != "block")
	{
		explosionLimits[0] = true;
		explosionLimits[1] = true;
	}
	else if (p->posY - 1 >= 0 && grid[p->posX][p->posY - 1] != "block")
	{
		explosionLimits[1] = true;
	}
	if (p->posY + 2 <= 10 && grid[p->posX][p->posY + 2] != "block")
	{
		explosionLimits[6] = true;
		explosionLimits[7] = true;
	}
	else if (p->posY + 1 <= 10 && grid[p->posX][p->posY + 1] != "block")
	{
		explosionLimits[6] = true;
	}
	if (p->posX - 2 >= 0 && grid[p->posX - 2][p->posY] != "block")
	{
		explosionLimits[2] = true;
		explosionLimits[3] = true;
	}
	else if (p->posX - 1 >= 0 && grid[p->posX - 1][p->posY] != "block")
	{
		explosionLimits[2] = true;
	}
	if (p->posX + 2 <= 12 && grid[p->posX + 2][p->posY] != "block")
	{
		explosionLimits[4] = true;
		explosionLimits[5] = true;
	}
	else if (p->posX + 1 <= 12 && grid[p->posX + 1][p->posY] != "block")
	{
		explosionLimits[4] = true;
	}
}

void Level::restartExplosionLimits()
{
	for (int i = 0; i <= 7; i++)
	{
		explosionLimits[i] = false;
	}
}

void Level::checkDamage(Player *p)
{
	if (explosionLimits[0])
	{
		if (grid[p->ptrBomb->posX][p->ptrBomb->posY - 2] == "player1")
		{
			p1->lives--;
			if(p->getPlayerTag() == 2) p2->points += 100;
			grid[p->ptrBomb->posX][p->ptrBomb->posY - 2] = "empty";
		}
		else if (grid[p->ptrBomb->posX][p->ptrBomb->posY - 2] == "player2")
		{
			p2->lives--;
			if (p->getPlayerTag() == 1) p1->points += 100;
			grid[p->ptrBomb->posX][p->ptrBomb->posY - 2] = "empty";
		}
		else if (grid[p->ptrBomb->posX][p->ptrBomb->posY - 2] == "wall")
		{
			p->points += 15;
			//destroy wall
			grid[p->ptrBomb->posX][p->ptrBomb->posY - 2] = "empty";
		}
	}
	if (explosionLimits[1])
	{
		if (grid[p->ptrBomb->posX][p->ptrBomb->posY - 1] == "player1")
		{
			p1->lives--;
			if (p->getPlayerTag() == 2) p2->points += 100;
			grid[p->ptrBomb->posX][p->ptrBomb->posY - 1] = "empty";
		}
		else if (grid[p->ptrBomb->posX][p->ptrBomb->posY - 1] == "player2")
		{
			p2->lives--;
			if (p->getPlayerTag() == 1) p1->points += 100;
			grid[p->ptrBomb->posX][p->ptrBomb->posY - 1] = "empty";
		}
		else if (grid[p->ptrBomb->posX][p->ptrBomb->posY - 1] == "wall")
		{
			p->points += 15;
			//destroy wall
			grid[p->ptrBomb->posX][p->ptrBomb->posY - 1] = "empty";
		}
	}
	if (explosionLimits[2])
	{

		if (grid[p->ptrBomb->posX-1][p->ptrBomb->posY] == "player1")
		{
			p1->lives--;
			if (p->getPlayerTag() == 2) p2->points += 100;
			grid[p->ptrBomb->posX-1][p->ptrBomb->posY] = "empty";
		}
		else if (grid[p->ptrBomb->posX-1][p->ptrBomb->posY] == "player2")
		{
			p2->lives--;
			if (p->getPlayerTag() == 1) p1->points += 100;
			grid[p->ptrBomb->posX - 1][p->ptrBomb->posY] = "empty";
		}
		else if (grid[p->ptrBomb->posX-1][p->ptrBomb->posY] == "wall")
		{
			p->points += 15;
			//destroy wall
			grid[p->ptrBomb->posX - 1][p->ptrBomb->posY] = "empty";
		}
	}
	if (explosionLimits[3])
	{
		if (grid[p->ptrBomb->posX - 2][p->ptrBomb->posY] == "player1")
		{
			p1->lives--;
			if (p->getPlayerTag() == 2) p2->points += 100;
			grid[p->ptrBomb->posX - 2][p->ptrBomb->posY] = "empty";
		}
		else if (grid[p->ptrBomb->posX -2][p->ptrBomb->posY] == "player2")
		{
			p2->lives--;
			if (p->getPlayerTag() == 1) p1->points += 100;
			grid[p->ptrBomb->posX - 2][p->ptrBomb->posY] = "empty";
		}
		else if (grid[p->ptrBomb->posX - 2][p->ptrBomb->posY] == "wall")
		{
			p->points += 15;
			//destroy wall
			grid[p->ptrBomb->posX - 2][p->ptrBomb->posY] = "empty";
		}
	}
	if (explosionLimits[4])
	{
		if (grid[p->ptrBomb->posX + 1][p->ptrBomb->posY] == "player1")
		{
			p1->lives--;
			if (p->getPlayerTag() == 2) p2->points += 100;
			grid[p->ptrBomb->posX + 1][p->ptrBomb->posY] = "empty";
		}
		else if (grid[p->ptrBomb->posX + 1][p->ptrBomb->posY] == "player2")
		{
			p2->lives--;
			if (p->getPlayerTag() == 1) p1->points += 100;
			grid[p->ptrBomb->posX + 1][p->ptrBomb->posY] = "empty";
		}
		else if (grid[p->ptrBomb->posX + 1][p->ptrBomb->posY] == "wall")
		{
			p->points += 15;
			//destroy wall
			grid[p->ptrBomb->posX + 1][p->ptrBomb->posY] = "empty";
		}
	}
	if (explosionLimits[5])
	{
		if (grid[p->ptrBomb->posX + 2][p->ptrBomb->posY] == "player1")
		{
			p1->lives--;
			if (p->getPlayerTag() == 2) p2->points += 100;
			grid[p->ptrBomb->posX + 2][p->ptrBomb->posY] = "empty";
		}
		else if (grid[p->ptrBomb->posX + 2][p->ptrBomb->posY] == "player2")
		{
			p2->lives--;
			if (p->getPlayerTag() == 1) p1->points += 100;
			grid[p->ptrBomb->posX + 2][p->ptrBomb->posY] = "empty";
		}
		else if (grid[p->ptrBomb->posX + 2][p->ptrBomb->posY] == "wall")
		{
			p->points += 15;
			//destroy wall
			grid[p->ptrBomb->posX + 2][p->ptrBomb->posY] = "empty";
		}
	}
	if (explosionLimits[6])
	{
		if (grid[p->ptrBomb->posX][p->ptrBomb->posY + 1] == "player1")
		{
			p1->lives--;
			if (p->getPlayerTag() == 2) p2->points += 100;
			grid[p->ptrBomb->posX][p->ptrBomb->posY + 1] = "empty";
		}
		else if (grid[p->ptrBomb->posX][p->ptrBomb->posY + 1] == "player2")
		{
			p2->lives--;
			if (p->getPlayerTag() == 1) p1->points += 100;
			grid[p->ptrBomb->posX][p->ptrBomb->posY - 1] = "empty";
		}
		else if (grid[p->ptrBomb->posX][p->ptrBomb->posY + 1] == "wall")
		{
			p->points += 15;
			//destroy wall
			grid[p->ptrBomb->posX][p->ptrBomb->posY + 1] = "empty";
		}
	}
	if (explosionLimits[7])
	{
		if (grid[p->ptrBomb->posX][p->ptrBomb->posY + 2] == "player1")
		{
			p1->lives--;
			if (p->getPlayerTag() == 2) p2->points += 100;
			grid[p->ptrBomb->posX][p->ptrBomb->posY + 2] = "empty";
		}
		else if (grid[p->ptrBomb->posX][p->ptrBomb->posY - 2] == "player2")
		{
			p2->lives--;
			if (p->getPlayerTag() == 1) p1->points += 100;
			grid[p->ptrBomb->posX][p->ptrBomb->posY + 2] = "empty";
		}
		else if (grid[p->ptrBomb->posX][p->ptrBomb->posY + 2] == "wall")
		{
			p->points += 15;
			//destroy wall
			grid[p->ptrBomb->posX][p->ptrBomb->posY + 2] = "empty";
		}
	}	
}
