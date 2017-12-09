#include "Player.h"

Player::Player(int num): playerTag{ num }, ptrBomb{nullptr}
{
	Renderer::Instance()->LoadTexture(PLAYER1_SPRITE, PATH_IMG + "player1.png");
	Renderer::Instance()->LoadTexture(PLAYER2_SPRITE, PATH_IMG + "player2.png");
	//les mesures del png de player1 i player2 són les mateixes.
	textWidth = Renderer::Instance()->GetTextureSize(PLAYER1_SPRITE).x;
	textHeight = Renderer::Instance()->GetTextureSize(PLAYER1_SPRITE).y;
	frameWidth = textWidth / 3;
	frameHeight = textHeight / 4;
	//per tant tots dos tenen el mateix PlayerRect.
	PlayerRect = { 0,0,frameWidth,frameHeight };

	//només canvia el punt inicial x,y.
	if (num == 1)
	{
		PlayerPosition = { 50,  SCREEN_HEIGHT / 2, 48, 48 };
	}
	else if (num == 2)
	{
		PlayerPosition = { SCREEN_WIDTH-50,  SCREEN_HEIGHT / 2, 48, 48 };
	}
}

Player::~Player()
{
}

int Player::getPlayerTag()
{
	return playerTag;
}

Bomb* Player::bomb()
{
	ptrBomb = new Bomb(PlayerPosition);
	return ptrBomb;
}

