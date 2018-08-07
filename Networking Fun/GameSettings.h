#pragma once

//Global settings for the game

class GameSettings
{
public:
	static void getDimensions(int &w, int &h);
	static void setDimensions(int w, int h);
private:
	GameSettings();
	~GameSettings();
	static int width;
	static int height;
};