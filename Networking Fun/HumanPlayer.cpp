#include "HumanPlayer.h"



HumanPlayer::HumanPlayer(const std::string& name) :
	Player(name)
{

}


HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::update()
{
	inputHandler();
}

void HumanPlayer::inputHandler()
{
	
}
