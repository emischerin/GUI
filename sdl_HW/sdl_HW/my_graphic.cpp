#include <SDL.h>

#include <iostream>
#include "XCross.h"
#include "FatRect.h"
#include "InputCaret.h"
#include "MainWindow.h"
#include "Header.h"
void DrawAliasedLine(SDL_Renderer* r)
{
	
	for (int i = 450; i > 449; i--) {
		for (int j = 600; j > 599; j--) {
			SDL_RenderDrawPoint(r, i, j);
			
		}
	}
	
}

bool MouseXInWindowRange(int& x)
{
	if ((x >= 400) && (x <= 400 + 800))
		return true;

	return false;
}

bool MouseYInWindowRange(int& y)
{
	if ((y >= 200) && (y <= 200 + 600))
		return true;

	return false;
}
bool MouseInWindow(int& x, int& y)
{
	return (MouseXInWindowRange(x)) && (MouseYInWindowRange(y));
}


void ProcessMouse(SDL_Renderer* r)
{
	int x, y;
	SDL_GetGlobalMouseState(&x, &y);

	if (MouseInWindow(x, y)) {
		SDL_SetRenderDrawColor(r, 0x30, 0x2F, 0x60, 255);
		return;
	}
		

	SDL_SetRenderDrawColor(r, 0x2d, 0x2A, 0x57, 255);

}





int main(int argc, char** argv)
{
	MainWindow mw(800, 600, "HELLO NORMAL WINDOW!");

	Header* h = new Header(35, 35);
	h->SetColor(62, 19, 66, 1);

	mw.SetHeader(h);
	
	return mw.StartLoop(MainWindow::LoopType::SIMPLE_APP);



}