#pragma once
#include <sdl.h>
#include <vector>

#include "control.h"
#include "Header.h"
#include "Window.h"

class MainWindow : public Window
{
public:

	MainWindow(int width, int height,const char* w_title);
	
	int StartLoop();
	
	 SDL_Window* GetWinPtr();
	 

	 

private:
	
	SDL_Surface* _screen_surface = nullptr;
	

	SDL_Color _background_color;
	

	Header* _header = nullptr;
	
	int InitGraphics();
	int MainLoop();

	void SetBackgroundColor();

	void Update();

};

