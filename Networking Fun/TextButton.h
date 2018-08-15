#pragma once
#include "ButtonBase.h"
#include "Text.h"
class TextButton :
	public ButtonBase
{
public:
	TextButton(SDL_Renderer* renderer, const char* text);
	~TextButton();
	void draw() override;
	void update() override;
	void setX(int x) override;
	void setY(int y) override;
private:
	Text * text_;
	SDL_Rect rect_;
	void onHover() override;
};

