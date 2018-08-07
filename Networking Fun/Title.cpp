#include "Title.h"

Title::Title(SDL_Renderer* renderer):
	GameState(renderer)
{
	std::cout << "Created Title" << std::endl;

	menu = new Sprite(m_renderer);

	menu->load("Assets/Graphics/Shrek.png");

	int w, h;
	GameSettings::getDimensions(w, h);
	menu->setWidthHeight(w, h);
	m_play = new MenuButton(m_renderer, "Assets/Graphics/play.png");
	m_multiplayer = new MenuButton(m_renderer, "Assets/Graphics/editor.png");
	m_quit = new MenuButton(m_renderer, "Assets/Graphics/quit.png");
	m_play->setX(375);
	m_play->setY(400);
	m_multiplayer->setX(375);
	m_multiplayer->setY(450);
	m_quit->setX(375);
	m_quit->setY(500);
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
}


Title::~Title()
{
	std::cout << "Title Destroyed" << std::endl;
	delete menu;
	delete m_play;
	delete m_multiplayer;
	delete m_quit;
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Title::update()
{
	m_play->update();
	m_multiplayer->update();
	m_quit->update();
	if (m_play->click())
	{
		request.state = GameState::STATE_MATCH;
	}
	if (m_quit->click())
	{
		request.state = GameState::STATE_QUIT;
	}
	if (m_multiplayer->click())
	{
		request.state = GameState::STATE_LOBBY;
	}
}

void Title::draw()
{
	SDL_RenderClear(m_renderer);
	menu->draw();
	m_play->draw();
	m_multiplayer->draw();
	m_quit->draw();
	SDL_RenderPresent(m_renderer);
}