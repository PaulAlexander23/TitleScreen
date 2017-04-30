#include "Intro.h"

CIntro::CIntro()
{
	quit = false;
	oSDL = new CSDL_Class(&quit, 640, 512);
	oBackground = new CBackground(oSDL->GetRenderer(), "data/IntroBackground.png", 640, 512);

	gfont = TTF_OpenFont("data/ostrich-black.ttf", 24);
	if (gfont == NULL)
	{
		std::cout << "Couldn't Load Font" << std::endl;
	}
	startBtn = new CBtn(oSDL->GetRenderer(), 320, 16 * 10, "New", gfont);
	loadBtn = new CBtn(oSDL->GetRenderer(), 320, 16 * 13, "Load", gfont);
	optionBtn = new CBtn(oSDL->GetRenderer(), 320, 16 * 16, "Options", gfont);
	quitBtn = new CBtn(oSDL->GetRenderer(), 320, 16 * 20, "Quit", gfont);
	omouse = new CMouse();
}


CIntro::~CIntro()
{
	delete omouse;
	TTF_CloseFont(gfont);
	delete startBtn;
	delete loadBtn;
	delete optionBtn;
	delete quitBtn;
	delete oBackground;
	delete oSDL;
}

void CIntro::intro()
{
	
	while (!quit)
	{
		oSDL->Begin();
		
		EventHandler();
		
		oBackground->Draw();
		startBtn->Draw();
		loadBtn->Draw();
		optionBtn->Draw();
		quitBtn->Draw();

		oSDL->End();
		_sleep(10);
	}
}

void CIntro::EventHandler()
{
	switch (oSDL->GetMainEvent()->type)
	{
	case SDL_QUIT:
	{
		quit = true;
		break;
	}
	case SDL_MOUSEBUTTONDOWN:
	{
		omouse->UpdateXY();
		if (oSDL->GetMainEvent()->button.button == SDL_BUTTON_LEFT)
		{

			if (startBtn->pressed == false && startBtn->InButton(omouse->GetX(), omouse->GetY()))
			{
				startBtn->pressed = true;
				std::cout << "Start" << std::endl;
			}
			if (loadBtn->pressed == false && loadBtn->InButton(omouse->GetX(), omouse->GetY()))
			{
				loadBtn->pressed = true;
				std::cout << "Load" << std::endl;
			}
			if (optionBtn->pressed == false && optionBtn->InButton(omouse->GetX(), omouse->GetY()))
			{
				optionBtn->pressed = true;
				std::cout << "Options" << std::endl;
			}
			if (quitBtn->pressed == false && quitBtn->InButton(omouse->GetX(), omouse->GetY()))
			{
				quitBtn->pressed = true;
				std::cout << "Quit" << std::endl;
				quit = true;
			}
		}
		
		break;
	}
	case SDL_MOUSEBUTTONUP:
	{
		startBtn->pressed = false;
		loadBtn->pressed = false;
		optionBtn->pressed = false;
		quitBtn->pressed = false;
		break;
	}
	default:
		break;
	}

}