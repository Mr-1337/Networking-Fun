#include "LobbyScreen.h"



void LobbyScreen::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderClear(m_renderer);
	switch (mode_)
	{
	case 0:
		host_.draw();
		join_.draw();
		break;
	case 1:

		break;
	case 2:

		break;
	}
	chatUI_->draw();
	SDL_RenderPresent(m_renderer);
}



void LobbyScreen::update()
{
	static bool set = false;
	switch (mode_)
	{
	case 0:
		if (host_.click())
		{
		
			if (SDLNet_ResolveHost(&hostIP_, NULL, 25570))
				std::cout << SDLNet_GetError() << std::endl;

			server_ = SDLNet_TCP_Open(&hostIP_);

			if (server_ == NULL)
				std::cout << SDLNet_GetError() << std::endl;

			mode_ = 1;
		
		}
		else if (join_.click())
		{

			if (SDLNet_ResolveHost(&hostIP_, "localhost", 25570))
				std::cout << SDLNet_GetError() << std::endl;
			SDLNet_TCP_Open(&hostIP_);
			mode_ = 2;
		}
		break;
	case 1:
		client_ = SDLNet_TCP_Accept(server_);
		if (client_ != NULL && !set)
		{
			std::cout << "ESTABLISHED CONNECTION!!!" << std::endl;
			set = true;
		}
		break;
	case 2:

		break;
	}
}

void LobbyScreen::eventHandler()
{
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (!chat_.empty() && e.key.keysym.sym == SDLK_BACKSPACE)
			{
				chat_.pop_back();
				if (!chat_.empty())
					chatUI_->updateText(chat_, { 0, 0, 0, 255 });
				else
					chatUI_->updateText(" ", { 0, 0, 0, 255 });
			}
			
		}
		else if (e.type == SDL_TEXTINPUT)
		{
			chat_ += e.text.text;
			chatUI_->updateText(chat_, { 0, 0, 0, 255 });
		}
		else if (e.type == SDL_QUIT)
			request.state = STATE_QUIT;
	}
}

LobbyScreen::LobbyScreen(SDL_Renderer* renderer) :
	GameState(renderer), host_(renderer, "Host Game"), join_(renderer, "Join Game")
{
	SDL_StartTextInput();
	chatUI_ = new Text(m_renderer, " ");
	chatUI_->load("Assets/Font/arial.ttf", 15, { 255, 255, 255, 255 });
	chatUI_->setX(20);
	host_.setY(500);
	join_.setY(500);
	host_.setX(200);
	join_.setX(400);
	mode_ = 0;
}


LobbyScreen::~LobbyScreen()
{
	SDL_StopTextInput();
}
