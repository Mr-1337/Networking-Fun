#pragma once
#include "Sprite.h"
#include <SDL_ttf.h>
class Text :
	public Sprite
{
public:
	Text(SDL_Renderer* renderer, std::string message);
	~Text();
	void load(std::string path, int pntSize, SDL_Color fontColor);
	void draw() override;
	void updateText(std::string text, SDL_Color fontColor);
private:
	TTF_Font* font;
	SDL_Surface* tempSurface;
	std::string m_string;
};

