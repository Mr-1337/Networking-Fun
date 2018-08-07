#include "Player.h"

Player::Player() :
	m_name("undefined")
{
	std::cout << "Challenger " << m_name << " approaches!" << std::endl;
}


Player::Player(const std::string& name) :
	m_name(name)
{
	std::cout << "Challenger " << name << " approaches!" << std::endl;
}


Player::~Player()
{
}