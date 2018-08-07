#include "Sprite.h"
#include "GameEngine.h"

Sprite::Sprite(SDL_Renderer* renderer)
	:m_renderer(renderer), m_flip(SDL_FLIP_NONE)
{
	if (renderer != NULL)
	{
		std::cout << "Sprite created!" << std::endl;
	}
	else
	{
		std::cout << "Renderer undefined for Sprite" << std::endl;
	}
}

Sprite::~Sprite()
{
	SDL_DestroyTexture(m_texture);
	std::cout << "Sprite destroyed!" << std::endl;
}

void Sprite::setFlip(SDL_RendererFlip flip)
{
	m_flip = flip;
}

void Sprite::setX(int x)
{
	m_dstRect.x = x;
}

void Sprite::setY(int y)
{
	m_dstRect.y = y;
}

void Sprite::setWidthHeight(int w, int h)
{
	m_dstRect.w = w;
	m_dstRect.h = h;
}

void Sprite::getWidthHeight(int* w, int* h)
{
	*w = m_dstRect.w;
	*h = m_dstRect.h;
}

SDL_Rect* Sprite::getRect()
{
	return &m_dstRect;
}

void Sprite::draw()
{
	if (m_renderer != NULL && m_texture != NULL)
	{
		SDL_RenderCopyEx(m_renderer, m_texture, NULL, &m_dstRect, angle, &pivot, m_flip);
	}
	else
	{
		//std::cout << "Renderer or texture are NULL" << std::endl;
	}
}

void Sprite::setAlpha(int alpha)
{
	if (alpha < 0)
		alpha = 0;
	if (alpha > 255)
		alpha = 255;
	if (SDL_SetTextureAlphaMod(m_texture, alpha) != 0)
		std::cout << SDL_GetError() << std::endl;
}

void Sprite::draw(SDL_Rect& clip)
{
	if (m_renderer != NULL && m_texture != NULL)
	{
		m_dstRect.w = clip.w;
		m_dstRect.h = clip.h;
		SDL_RenderCopy(m_renderer, m_texture, &clip, &m_dstRect);
	}
	else
	{
		std::cout << "Renderer, bounding rect, or texture are NULL" << std::endl;
	}
}


void Sprite::rotate(double angle, SDL_Point* pivot)
{
	if (pivot != NULL)
	{
		this->pivot = *pivot;
	}
	this->angle = angle;
}

void Sprite::load(const std::string& path)
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

			m_dstRect.x = 0;
			m_dstRect.y = 0;
			m_dstRect.w = tempSurface->w;
			m_dstRect.h = tempSurface->h;
			pivot.x = m_dstRect.x + m_dstRect.w / 2;
			pivot.y = m_dstRect.y + m_dstRect.h / 2;
			std::cout << "loaded texture " << path << " with dimensions of " << m_dstRect.w << " x " << m_dstRect.h << std::endl;
		}
	}
	SDL_FreeSurface(tempSurface);
}