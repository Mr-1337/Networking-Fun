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
	UDPsocket sock_;

	UDPpacket* packet_;

	TextButton host_;
	TextButton join_;

	std::string ipToString(IPaddress& ip);
	int stringToIP(std::string ip);

	std::string chat_;
	Text* chatUI_;
	int mode_;
	SDL_Event e;
};

