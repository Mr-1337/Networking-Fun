#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_mixer.h>

//Abstract type for different GameStates

class GameState
{
public:
	GameState(SDL_Renderer* renderer);
	virtual ~GameState();
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void eventHandler();
	virtual void revealed();

	enum states
	{
		STATE_NONE,
		STATE_POP,
		STATE_QUIT,
		STATE_PAUSE,
		STATE_INTRO,
		STATE_TITLE,
		STATE_MATCH,
		STATE_LOBBY,
		STATE_OPTIONS,
	};
	
	struct StateRequest
	{
		StateRequest()
		{
			popCurrent = true;
			popPrev = false;
			state = STATE_NONE;
		}
		bool popCurrent;
		bool popPrev;
		states state;
	};

	StateRequest getStateRequest();
protected:
	SDL_Renderer* m_renderer;
	StateRequest request;
	SDL_Event event_;

};

