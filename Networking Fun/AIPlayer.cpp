#include "AIPlayer.h"



AIPlayer::AIPlayer(const std::string& name) :
	Player(name)
{
}


AIPlayer::~AIPlayer()
{
}


void AIPlayer::update()
{
	inputHandler();
}

void AIPlayer::inputHandler()
{
}
