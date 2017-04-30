#pragma once

#include "stdafx.h"

class CSDL_Class
{
public:
	CSDL_Class(bool* quit, int ScreenWidth, int ScreenHeight);
	~CSDL_Class();

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;

};

