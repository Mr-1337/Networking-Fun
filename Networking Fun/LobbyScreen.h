#pragma once
#include "GameState.h"
#include "TextButton.h"
class LobbyScreen :
	public GameState
{
public:

	void draw() override;
	void update() override;

	LobbyScreen(SDL_Renderer* renderer);
	~LobbyScreen();

private:

	TextButton host_;
	TextButton join_;

};

