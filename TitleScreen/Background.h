#pragma once

#include "stdafx.h"

class CBackground
{
public:
	CBackground(SDL_Renderer* passed_renderer, std::string FilePath, int w, int h);
	~CBackground();

	void Draw();

private:
	SDL_Texture* image;
	SDL_Rect rect;

	SDL_Renderer* renderer;


};

