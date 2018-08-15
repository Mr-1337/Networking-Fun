#include "LobbyScreen.h"



void LobbyScreen::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	host_.draw();
	join_.draw();
	SDL_RenderPresent(m_renderer);
}

void LobbyScreen::update()
{
	host_.click();
	join_.click();
}

LobbyScreen::LobbyScreen(SDL_Renderer* renderer) :
	GameState(renderer), host_(renderer, "Host Game"), join_(renderer, "Join Game")
{
	host_.setY(500);
	join_.setY(500);
	host_.setX(200);
	join_.setX(400);
}


LobbyScreen::~LobbyScreen()
{
}
