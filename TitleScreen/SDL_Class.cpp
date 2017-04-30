#include "SDL_Class.h"

CSDL_Class::CSDL_Class(bool* quit, int ScreenWidth, int ScreenHeight)
{

	window = NULL;
	window = SDL_CreateWindow("TitleScreen", 100, 100, ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Window counldn't be created" << std::endl;
		*quit = true;
	}
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	mainEvent = new SDL_Event();
}

CSDL_Class::~CSDL_Class()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* CSDL_Class::GetRenderer()
{
	return renderer;
}

SDL_Event* CSDL_Class::GetMainEvent()
{
	return mainEvent;
}

void CSDL_Class::Begin()
{
	SDL_PollEvent(mainEvent);
	SDL_RenderClear(renderer);
}

void CSDL_Class::End()
{
	SDL_RenderPresent(renderer);
}