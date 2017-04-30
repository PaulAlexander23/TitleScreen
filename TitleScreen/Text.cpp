#include "Text.h"


CText::CText(SDL_Renderer* passed_renderer, int x, int y, std::string passed_text, TTF_Font *pfont)
{
	renderer = passed_renderer;
	text = passed_text;

	gfont = NULL;
	gfont = pfont;

	textSurface = NULL;
	textSurface = TTF_RenderText_Solid(gfont, text.c_str(), { 255, 255, 255 });

	renderedText = NULL;
	renderedText = SDL_CreateTextureFromSurface(renderer, textSurface);
	
	textRect.x = x - textSurface->w / 2;
	textRect.y = y - (textSurface->h - 4) / 2;
	textRect.h = textSurface->h;
	textRect.w = textSurface->w;

}


CText::~CText()
{
}

void CText::Draw()
{
	SDL_RenderCopy(renderer, renderedText, NULL, &textRect);
}