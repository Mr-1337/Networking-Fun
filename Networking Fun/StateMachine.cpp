#include "StateMachine.h"

StateMachine::StateMachine(SDL_Renderer* renderer):
	m_renderer(renderer)
{
	
}

StateMachine::~StateMachine()
{
	while (!stateStack.empty())
	{
		stateStack.pop();
	}
}

void StateMachine::setState(GameState::StateRequest newState)
{
	if (newState.popCurrent && newState.state != GameState::STATE_NONE)
	{
		stateStack.pop();
		if (newState.popPrev)
		{
			std::cout << "Popping previous state: \n";
			if (!stateStack.empty())
			{
				stateStack.pop();
			}
		}
		else
		{
			if (!stateStack.empty())
				stateStack.top()->revealed();
		}

	}
	switch (newState.state)
	{
	case GameState::STATE_TITLE:
		stateStack.push(std::make_unique<Title>(m_renderer));
		break;

	case GameState::STATE_MATCH:
		stateStack.push(std::make_unique<MatchScreen>(m_renderer));
		break;

	case GameState::STATE_LOBBY:
		stateStack.push(std::make_unique<LobbyScreen>(m_renderer));
		break;
	}
}

GameState::StateRequest StateMachine::getStateRequest()
{
	return stateStack.top()->getStateRequest();
}

void StateMachine::draw()
{
	stateStack.top()->draw();
}

void StateMachine::update()
{
	//std::cout << stateStack.size() << std::endl;
	stateStack.top()->update();
}

void StateMachine::eventHandler()
{
	stateStack.top()->eventHandler();
}