#pragma once
#include "GameState.h"
#include "GameSettings.h"
#include "MenuButton.h"
class Title :
	public GameState
{
public:
	Title(SDL_Renderer* renderer);
	~Title();
	void update() override;
	void draw() override;

private:
	Sprite* menu;

	MenuButton* m_play;
	MenuButton* m_multiplayer;
	MenuButton* m_quit;
};

