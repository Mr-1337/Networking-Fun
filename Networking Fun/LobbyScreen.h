#pragma once
#include <SDL_net.h>
#include "GameState.h"
#include "TextButton.h"
class LobbyScreen :
	public GameState
{
public:

	void draw() override;
	void update() override;
	void eventHandler() override;

	LobbyScreen(SDL_Renderer* renderer);
	~LobbyScreen();

private:

	IPaddress hostIP_;
	TCPsocket server_;
	TCPsocket client_;

	TextButton host_;
	TextButton join_;
	std::string chat_;
	Text* chatUI_;
	int mode_;
	SDL_Event e;
};

