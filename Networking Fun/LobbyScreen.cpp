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
	int result;
	switch (mode_)
	{
	case 0:
		if (host_.click())
		{
		
			if (SDLNet_ResolveHost(&hostIP_, NULL, 25570))
				std::cout << SDLNet_GetError() << std::endl;

			sock_ = SDLNet_UDP_Open(hostIP_.port);

			if (sock_ == NULL)
				std::cout << SDLNet_GetError() << std::endl;

			mode_ = 1;
		
		}
		else if (join_.click())
		{

			if (SDLNet_ResolveHost(&hostIP_, "192.168.86.208", 25570))
				std::cout << SDLNet_GetError() << std::endl;

			std::cout << ipToString(hostIP_) << std::endl;

			sock_ = SDLNet_UDP_Open(0);
			if (sock_ == NULL)
				std::cout << SDLNet_GetError() << std::endl;
			packet_->address = hostIP_;
			packet_->len = 6;
			memcpy(packet_->data, "HELLO", packet_->len);
			std::cout << "Attempting to send to " << packet_->address.host << " on port " << packet_->address.port << std::endl;
			mode_ = 2;
			std::cout << SDLNet_UDP_Send(sock_, -1, packet_) << std::endl;
		}
		break;
	case 1:
		packet_->len = 6;
		result = SDLNet_UDP_Recv(sock_, packet_);
		if (result > 0)
		{
			std::cout << "Received connection from " << packet_->address.host << " on port " << packet_->address.port << std::endl;
		}
		else if (result < 0)
			std::cout << SDLNet_GetError() << std::endl;
		else if (result == 0)
			std::cout << "nothing to see here\n";
		break;
	case 2:
		packet_->len = 6;
		result = SDLNet_UDP_Recv(sock_, packet_);
		if (result > 0)
		{
			std::cout << "Received connection from " << packet_->address.host << " on port " << packet_->address.port << std::endl;
		}
		else if (result < 0)
			std::cout << SDLNet_GetError() << std::endl;
		else if (result == 0)
			std::cout << "nothing to see here\n";
		break;
	}
}

//Turn an SDLNet IP into a string
std::string LobbyScreen::ipToString(IPaddress& ip)
{
	std::string s;
	//IP
	for (int i = 0; i < 4; i++)
	{
		s += std::to_string((ip.host >> (i*8)) & 255) + '.';
	}
	s.pop_back();
	s += ":";
	//PORT
	s += std::to_string(((ip.port & 255) << 8) | ((ip.port >> 8) & 255));
	return s;
}

int LobbyScreen::stringToIP(std::string ip)
{
	unsigned int host = 0;

	return host;
}

void LobbyScreen::eventHandler()
{
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_RETURN)
			{
				if (mode_ == 1)
				{
						
				}
				else if (mode_ == 2)
				{
 					std::cout << SDLNet_UDP_Send(sock_, -1, packet_) << std::endl; 
					std::cout << packet_->status << std::endl;
				}
 			}

			else if (!chat_.empty() && e.key.keysym.sym == SDLK_BACKSPACE)
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
	packet_ = SDLNet_AllocPacket(32);
	if (!packet_)
		std::cout << SDLNet_GetError() << std::endl;

	//DO NOT HALT
}


LobbyScreen::~LobbyScreen()
{
	SDL_StopTextInput();
}
