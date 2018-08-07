#include "MatchScreen.h"


MatchScreen::MatchScreen(SDL_Renderer * renderer) :
	GameState(renderer)
{
	std::cout << "Starting match" << std::endl;
}

void MatchScreen::update()
{
	for (auto p : m_players)
	{
		p->update();
	}
}

void MatchScreen::draw()
{
	for (auto p : m_players)
	{
		p->draw();
	}
}

MatchScreen::~MatchScreen()
{
	std::cout << "Destroyed match" << std::endl;
}
