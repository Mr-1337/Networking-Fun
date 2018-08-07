#pragma once

#include <stack>
#include <memory>
#include "GameState.h"
#include "Title.h"
#include "MatchScreen.h"
#include "LobbyScreen.h"

//Houses all the different game states, facilitates their usage, and contains logic for switching
class StateMachine
{
public:
	StateMachine(SDL_Renderer* renderer);
	~StateMachine();
	void setState(GameState::StateRequest newState);
	GameState::StateRequest getStateRequest();
	void update();
	void draw();

private:
	std::stack <std::unique_ptr<GameState>> stateStack;
	SDL_Renderer* m_renderer;
};

