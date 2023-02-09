#pragma once
#include <sdl.h>
#include <vector>
class MainWindow
{
public:

	MainWindow(int width, int height,const char* w_title);
	
	int StartLoop();
	
private:
	SDL_Window* _main_window = nullptr;
	SDL_Surface* _screen_surface = nullptr;
	SDL_Renderer* _render = nullptr;
	int _width = 0;
	int _height = 0;
	int _x = 0;
	int _y = 0;
	uint32_t _flags = 0;
	const char* _title;
	int InitGraphics();
	int MainLoop();

	

};

