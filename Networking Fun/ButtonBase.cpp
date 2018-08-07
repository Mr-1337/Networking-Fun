#include "ButtonBase.h"

ButtonBase::ButtonBase(SDL_Renderer* renderer)
	:UIElement(renderer), mDown(false)
{
}

bool ButtonBase::click()
{
	if (SDL_BUTTON_LMASK & SDL_GetMouseState(&mX,&mY))
	{
		if (!mDown && mouseInBounds())
		{
			mDown = true;
			return true;
		}
		else
		{
			mDown = true;
			return false;
		}
	}
	else
	{
		mDown = false;
		return false;
	}
}

bool ButtonBase::mouseInBounds()
{
	SDL_Rect* sRect = m_sprite->getRect();
	if ((mX >= sRect->x) && (mX <= sRect->x + sRect->w) && (mY >= sRect->y) && (mY <= sRect->y + sRect->h))
	{
		return true;
	}
	else
	{
		return false;
	}
}

ButtonBase::~ButtonBase()
{
}
