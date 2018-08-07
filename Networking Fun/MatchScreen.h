#pragma once
#include "GameState.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

#include <vector>

class MatchScreen :
	public GameState
{

public:
	MatchScreen(SDL_Renderer* renderer);
	~MatchScreen();
	void update() override;
	void draw() override;
private:
	std::vector<std::shared_ptr<Player>> m_players;
};

