#include "AnimatedSprite.h"


AnimatedSprite::AnimatedSprite(SDL_Renderer* renderer, SDL_Rect rect)
	:Sprite(renderer), frame(0), frameTime(1000), drawRegion(rect)
{
	
}


AnimatedSprite::~AnimatedSprite()
{
}


void AnimatedSprite::setFrameTime(int time)
{
	frameTime = time;
}


void AnimatedSprite::load(std::string path)
{
	SDL_Surface* tempSurface;
	tempSurface = IMG_Load(path.c_str());
	if (tempSurface == NULL)
	{
		std::cout << "Error loading image! Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		if (m_renderer == NULL)
		{
			std::cout << "Rendering context is undefined for this sprite!" << std::endl;
		}
		else
		{
			m_texture = SDL_CreateTextureFromSurface(m_renderer, tempSurface);
			m_dstRect = drawRegion;
			std::cout << "loaded clipped texture " << path << " with dimensions of " << m_dstRect.w << " x " << m_dstRect.h << std::endl;
		}
	}
	SDL_FreeSurface(tempSurface);
	timer.start();
}

void AnimatedSprite::draw()
{
	if (timer.getTicks() > frameTime)
	{
		frame++;
		timer.restart();
	}
	if (frame > 6)
		frame = 0;
	drawRegion.x = drawRegion.w * frame;
	SDL_RenderCopyEx(m_renderer, m_texture, &drawRegion, &m_dstRect, angle, &pivot, m_flip);
}
