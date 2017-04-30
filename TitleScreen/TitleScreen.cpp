// TitleScreen.cpp : Defines the entry point for the console application.
//
//Aim: To set up a working title screen, optimise the classes and add text via sdl

#include "stdafx.h"
#include"Intro.h"


int main(int argc, char *argv[])
{
	TTF_Init();

	CIntro* intro = new CIntro();
	intro->intro();
	delete intro;

	TTF_Quit();

	return 0;
}

