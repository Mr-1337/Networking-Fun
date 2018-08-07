#pragma once
#include <SDL.h>
#include <string>
#include <type_traits>
#include <iostream>

class Player
{
public:
	Player();
	Player(const std::string& name);
	virtual ~Player();
	virtual void update() = 0;
	virtual void draw() = 0;

protected:
	virtual void inputHandler() = 0;
	const std::string m_name;

};

