#include "Text.h"

Text::Text(SDL_Renderer* renderer, std::string message)
	:Sprite(renderer), m_string(message)
{
	
}


Text::~Text()
{
	std::cout << "Text Destroyed" << std::endl;
	//TTF_CloseFont(font);
}

void Text::load(std::string path, int pntSize, SDL_Color fontColor)
{
	font = TTF_OpenFont(path.c_str(), pntSize);
	tempSurface = TTF_RenderText_Blended(font, m_string.c_str(), fontColor);
	m_dstRect.w = tempSurface->w;
	m_dstRect.h = tempSurface->h;
	m_dstRect.x = 0;
	m_dstRect.y = 0;
	m_texture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
}


void Text::draw()
{
	SDL_RenderCopy(m_renderer, m_texture, NULL, &m_dstRect);
}


void Text::updateText(std::string text, SDL_Color fontColor)
{
	if (font == nullptr)
		throw std::runtime_error("Make sure to load a font first genius");
	SDL_DestroyTexture(m_texture);
	m_string = text;
	tempSurface = TTF_RenderText_Blended(font, m_string.c_str(), fontColor);
	m_dstRect.w = tempSurface->w;
	m_dstRect.h = tempSurface->h;
	m_texture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
}