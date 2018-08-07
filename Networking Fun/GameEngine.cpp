#include "GameEngine.h"

GameEngine::GameEngine(std::string title)
	: m_quit(false)
{
	//Only let the application loop execute if window creation and renderer creation succeed

	int width, height;
	GameSettings::getDimensions(width, height);
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (m_window == NULL)
	{
		std::cout << "Window creation failed! Error: " << SDL_GetError() << std::endl;
		m_quit = true;
	}
	else
	{
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (m_renderer == NULL)
		{
			std::cout << "Renderer creation failed! Error: " << SDL_GetError() << std::endl;
			m_quit = true; 
		}
		else
		{
			SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
			stateMachine = new StateMachine(m_renderer);
			std::cout << "Engine construction successful!" << std::endl;

			GameState::StateRequest firstState;
			firstState.popCurrent = false;
			firstState.popPrev = false;
			firstState.state = GameState::STATE_TITLE;
			stateMachine->setState(firstState);
		}
	}
}

GameEngine::~GameEngine()
{
	delete stateMachine;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void GameEngine::appLoop()
{
	//Loop the program until the state machine requests to quit or the user closes the program
	//Update and draw based on current game state
	while (!m_quit)
	{
		if (stateMachine->getStateRequest().state != GameState::STATE_QUIT)
		{
			stateMachine->setState(stateMachine->getStateRequest());
			eventHandler();
			stateMachine->update();
			stateMachine->draw();
		}
		else
		{
			m_quit = true;
		}
	}
}

void GameEngine::eventHandler()
{
	while (SDL_PollEvent(&m_event) != 0)
	{
		if (m_event.type == SDL_QUIT)
		{
			m_quit = true;
		}
	}
}