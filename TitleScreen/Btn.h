#pragma once

#include "stdafx.h"
#include "Text.h"

class CBtn
{
public:
	CBtn(SDL_Renderer* passed_renderer, int x, int y, std::string passed_text, TTF_Font *pfont);
	~CBtn();
	void Draw();
	bool InButton(int x, int y);

	bool pressed;

	

private:
	TTF_Font* gfont;
	SDL_Texture* image;
	SDL_Texture* renderedText;
	SDL_Renderer* renderer;
	SDL_Surface* textSurface;
	SDL_Rect rect;
	SDL_Rect textRect;
	std::string text;
	CText* message;
};

