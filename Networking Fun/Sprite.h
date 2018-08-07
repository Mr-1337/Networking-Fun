#pragma once

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

//Represents a drawable image

class Sprite
{
public:
	Sprite (SDL_Renderer* renderer);
	~Sprite();
	virtual void load(const std::string& path);
	virtual void draw();
	void draw(SDL_Rect& clip);
	void setX(int x);
	void setY(int y);
	void setAlpha(int alpha);
	void setWidthHeight(int w, int h);
	void getWidthHeight(int* w, int* h);
	void rotate(double angle, SDL_Point* pivot);
	void setFlip(SDL_RendererFlip flip);
	SDL_Rect* getRect();
	
private:

protected:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	SDL_Rect m_dstRect;
	double angle;
	SDL_Point pivot;
	SDL_RendererFlip m_flip;
};