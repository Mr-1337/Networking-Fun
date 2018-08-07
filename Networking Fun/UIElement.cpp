#include "UIElement.h"

UIElement::UIElement(SDL_Renderer* renderer)
	:m_renderer(renderer), m_sprite(std::make_unique<Sprite>(renderer))
{
}


UIElement::~UIElement()
{
}


void UIElement::setX(int X)
{
	x = X;
	m_sprite->setX(x);
}

void UIElement::setY(int Y)
{
	y = Y;
	m_sprite->setY(y);
}
