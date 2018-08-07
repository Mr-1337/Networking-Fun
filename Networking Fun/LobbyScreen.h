#pragma once
#include "GameState.h"
class LobbyScreen :
	public GameState
{
public:

	void draw() override;
	void update() override;

	LobbyScreen(SDL_Renderer* renderer);
	~LobbyScreen();
};

