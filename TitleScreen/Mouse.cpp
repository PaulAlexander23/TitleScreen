#include "Mouse.h"


CMouse::CMouse()
{
	x = 0;
	y = 0;
}


CMouse::~CMouse()
{
}

int CMouse::GetX()
{
	return x;
}

int CMouse::GetY()
{
	return y;
}

void CMouse::UpdateXY()
{
	SDL_GetMouseState(&x,&y);
}