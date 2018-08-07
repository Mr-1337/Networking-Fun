#include "GameSettings.h"

GameSettings::GameSettings()
{
}


GameSettings::~GameSettings()
{
}

int GameSettings::width;
int GameSettings::height;

void GameSettings::getDimensions(int &w, int &h)
{
	w = width;
	h = height;
}


void GameSettings::setDimensions(int w, int h)
{
	width = w;
	height = h;
}