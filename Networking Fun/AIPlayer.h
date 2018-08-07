#pragma once
#include "Player.h"
class AIPlayer :
	public Player
{
public:
	AIPlayer(const std::string& name);
	~AIPlayer();
	void update() override;
private:
	void inputHandler() override;
};

