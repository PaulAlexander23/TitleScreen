#include "Btn.h"

CBtn::CBtn(SDL_Renderer* passed_renderer, int x, int y, std::string passed_text, TTF_Font *pfont)
{
	renderer = passed_renderer;
	image = NULL;
	image = IMG_LoadTexture(renderer, "data/button1.png");
	if (image == NULL){
		std::cout << "Couldn't Load " << "data/button1.png" << std::endl;
	}
	rect.x = x - 64;
	rect.y = y - 16;
	rect.w = 128;
	rect.h = 32;
	text = passed_text;
	gfont = NULL;
	gfont = pfont;
	
	
	message = new CText(passed_renderer, x, y, passed_text, gfont);

	Draw();
	pressed = false;
}


CBtn::~CBtn()
{
	delete message;
	SDL_DestroyTexture(image);
}

void CBtn::Draw()
{
	SDL_RenderCopy(renderer, image, NULL, &rect);
	message->Draw();
}


bool CBtn::InButton(int x, int y)
{
	if (rect.x < x && x < rect.x + rect.w && rect.y < y && y < rect.y + rect.h)
	{
		return 1;
	}
	else
	{
		return 0;
	}


}