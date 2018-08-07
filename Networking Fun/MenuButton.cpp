#include "MenuButton.h"

MenuButton::MenuButton(SDL_Renderer* renderer, std::string path):
	ButtonBase(renderer)
{
	m_sprite->load(path);
}


MenuButton::~MenuButton()
{
}


void MenuButton::onHover()
{
	SDL_Rect* rect = m_sprite->getRect();
	m_sprite->setWidthHeight(70, 50);
	m_sprite->setX(x-10);
	m_sprite->setY(y-10);
}

void MenuButton::update()
{
	if (mouseInBounds())
	{
		onHover();
	}
	else
	{
		m_sprite->setWidthHeight(50, 30);
		m_sprite->setX(x);
		m_sprite->setY(y);
	}
}

void MenuButton::draw()
{
	m_sprite->draw();
}
