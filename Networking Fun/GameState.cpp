#include "GameState.h"

GameState::GameState(SDL_Renderer* renderer)
	: m_renderer(renderer)
{
	if (m_renderer == NULL)
		std::cout << "Renderer is INVALID\n";
}

GameState::~GameState()
{
}

void GameState::revealed()
{
	request.state = STATE_NONE;
	request.popCurrent = true;
	request.popPrev = false;
}

GameState::StateRequest GameState::getStateRequest()
{
	return request;
}
