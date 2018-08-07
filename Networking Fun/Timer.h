#pragma once
#include <SDL.h>
class Timer
{
public:
	Timer();
	void start();
	void pause();
	void stop();
	void restart();
	int getTicks();
	~Timer();
private:
	unsigned int ticks;
};

