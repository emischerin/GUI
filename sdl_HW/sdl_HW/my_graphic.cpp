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



//void MainAppLoop(SDL_Window* main_window,SDL_Surface* mw_surface)
//{
//	SDL_Event e;
//	bool q = false;
//	SDL_Renderer* rend = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
//	
//	SDL_Rect r;
//	SDL_Rect window_rect;
//	window_rect.x = 0;
//	window_rect.y = 0;
//	window_rect.h = 600;
//	window_rect.w = 800;
//
//	
//
//	r.x = 150; r.y = 150;
//	r.h = 50; r.w = 300;
//	
//	SDL_Rect* draw = new SDL_Rect();
//
//	draw->x = 10; draw->y = 150;
//	draw->h = 75; draw->w = 76;
//	InputCaret inp_caret(100, 100, 3, 10);
//	inp_caret.SetInvisibilityColor(0x49, 0x65, 0x82, 1);
//	inp_caret.SetRenderer(rend);
//	while (1) {
//		while (SDL_PollEvent(&e)) {
//				
//
//			uint32_t event_t = e.type;
//
//			if (event_t == SDL_QUIT) return;
//
//
//			
//
//		}
//
//		SDL_Rect* line_test = new SDL_Rect();
//		line_test->x = 10; line_test->y = 100;
//		line_test->w = 85; line_test->h = 2;
//		
//		
//		SDL_Rect rx_test;
//		rx_test.x = 20;
//		rx_test.y = 300;
//		rx_test.w = 75;
//		rx_test.h = 75;
//		
//		FatRect fat_t(300, 300, 100, 100);
//		fat_t.SetRenderer(rend);
//
//		XCross x_test(rx_test,XCross::RECT_VISIBLE);
//		x_test.SetRenderer(rend);
//		x_test.SetColor(0xFF, 0xFF, 0xFF, 1);
//		SDL_SetRenderDrawColor(rend, 0x49, 0x65, 0x82, 1);
//		SDL_FillRect(mw_surface, NULL, 0x2d2A57);
//		SDL_SetRenderDrawColor(rend, 0x2d, 0x2A, 0x57, 255);
//		SDL_RenderClear(rend);
//		ProcessMouse(rend);
//
//		
//		/*SDL_RenderFillRect(rend, &window_rect);
//		x_test.ImplBehaviour();
//		fat_t.Draw();*/
//		/*SDL_SetRenderDrawColor(rend, 0xAF, 0xC9, 0xFA, 255);
//		SDL_RenderDrawLine(rend, 15, 15, 100, 15);
//		SDL_RenderDrawLine(rend, 15, 16, 100, 16);
//		SDL_RenderFillRect(rend, line_test);
//		SDL_SetRenderDrawColor(rend, 0x82, 0x56, 0x49, 1);
//		SDL_RenderFillRect(rend, &r);
//		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
//		SDL_RenderDrawRect(rend, draw);*/
//		//DrawAliasedLine(rend);
//	
//		//SDL_RenderDrawPoint(rend, 450, 500);
//		//SDL_RenderDrawPoint(rend, 400, 550);
//		
//		inp_caret.Draw();
//		
//		//SDL_RenderGeometry
//		
//		SDL_RenderPresent(rend);
//		
//		//SDL_RenderFillRect(rend, &window);
//
//		//SDL_SetRenderDrawColor(rend, 0x82, 0x56, 0x49, 255);
//
//		//SDL_RenderFillRect(rend, &r);
//		//
//		////SDL_SetRenderDrawColor(rend, 0xfc, 0x03, 0x28, 255);
//		//
//		//SDL_RenderPresent(rend);
//		
//
//	}
//}

int main(int argc, char** argv)
{
	MainWindow mw(800, 600, "HELLO NORMAL WINDOW!");

	Header* h = new Header(35, 35);
	h->SetColor(62, 19, 66, 1);

	mw.AddControl(h);

	mw.StartLoop(MainWindow::LoopType::SIMPLE_APP);
	//SDL_Window* w = NULL;

	//SDL_Surface* screen = NULL;

	//if (SDL_Init(SDL_INIT_VIDEO) < 0) {
	//	std::cout << "INIT ERROR!" << std::endl;
	//	return -1;
	//}


	//
	//w = SDL_CreateWindow("My custom window", 400,200 ,
	//	 800, 600, SDL_WINDOW_SHOWN |SDL_WINDOW_BORDERLESS);

	//if (!w) {
	//	std::cout << "ERROR CREATING WINDOW!" << std::endl;
	//	return -2;
	//}

	///*screen = SDL_GetWindowSurface(w);

	//SDL_FillRect(screen, NULL, 0x2d2A57);*/
	//
	//SDL_UpdateWindowSurface(w);

	//MainAppLoop(w,screen);

	//SDL_DestroyWindow(w);

	SDL_Quit();

	return 0;



}