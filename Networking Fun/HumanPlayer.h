#pragma once
#include "Player.h"
#include "GameSettings.h"
class HumanPlayer :
	public Player
{
public:
	HumanPlayer(const std::string& name);
	~HumanPlayer();
	void update() override;
private:
	void inputHandler() override;
};

