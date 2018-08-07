#include "Timer.h"



Timer::Timer()
{
}

void Timer::start()
{
	ticks = SDL_GetTicks();
}

void Timer::pause()
{

}

void Timer::stop()
{
	ticks = 0;
}

int Timer::getTicks()
{
	return (SDL_GetTicks() - ticks);
}

Timer::~Timer()
{
}

void Timer::restart()
{
	stop();
	start();
}
