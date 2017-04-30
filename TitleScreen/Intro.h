#pragma once

#include "stdafx.h"
#include "SDL_Class.h"
#include "Background.h"
#include "Btn.h"
#include "Mouse.h"

class CIntro
{
public:
	CIntro();
	~CIntro();

	void intro();
	
private:
	void EventHandler();
	
	bool quit;
	CSDL_Class* oSDL;
	CBackground* oBackground;
	TTF_Font* gfont;
	CBtn* startBtn;
	CBtn* loadBtn;
	CBtn* optionBtn;
	CBtn* quitBtn;
	CMouse* omouse;
	
};

