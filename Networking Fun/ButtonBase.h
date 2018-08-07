#pragma once
#include "Sprite.h"
#include "UIElement.h"
class ButtonBase
	:public UIElement
{
public:
	ButtonBase(SDL_Renderer* renderer);
	bool click();
	virtual ~ButtonBase()=0;	

protected:
	
	virtual void onHover() = 0;
	bool mouseInBounds();
	int mX;
	int mY;

	bool mDown;
	
};

