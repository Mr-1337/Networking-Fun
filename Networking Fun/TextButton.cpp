#include "TextButton.h"



TextButton::TextButton(SDL_Renderer* renderer, const char* text) :
	ButtonBase(renderer)
{
	text_ = new Text(m_renderer, text);
	text_->load("Assets/Font/Halo3.ttf", 24, { 0,255,0,255 });
	text_->getWidthHeight(&rect_.w, &rect_.h);
	m_sprite.reset(text_);
}


TextButton::~TextButton()
{
}

void TextButton::draw()
{
	SDL_SetRenderDrawColor(m_renderer, 127, 25, 69, 115);
	SDL_RenderFillRect(m_renderer, &rect_);
	text_->draw();
}

void TextButton::update()
{
}

void TextButton::setX(int x)
{
	this->x = x;
	text_->setX(x);
	rect_.x = x;
}

void TextButton::setY(int y)
{
	this->y = y;
	text_->setY(y);
	rect_.y = y;
}

void TextButton::onHover()
{
}
