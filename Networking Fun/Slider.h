#pragma once
#include "ButtonBase.h"
#include <SDL_mixer.h>
class Slider :
	public ButtonBase
{
public:
	Slider(SDL_Renderer* renderer);
	void onHover() override;
	void update() override;
	void draw() override;
	void setY(int y) override;
	void setX(int x) override;
	~Slider();
private:
	SDL_Rect wedge;
};

