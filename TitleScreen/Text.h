#pragma once

#include "stdafx.h"

class CText
{
public:
	CText(SDL_Renderer* passed_renderer, int x, int y, std::string passed_text, TTF_Font *pfont);
	~CText();

	void Draw();

private:
	TTF_Font* gfont;
	SDL_Texture* image;
	SDL_Texture* renderedText;
	SDL_Renderer* renderer;
	SDL_Surface* textSurface;
	SDL_Rect rect;
	SDL_Rect textRect;
	std::string text;

};

