#pragma once
#include <sdl.h>
#include <vector>
#include "bsp_tree.h"
#include "control.h"

class MainWindow
{
public:

	MainWindow(int width, int height,const char* w_title);
	
	int StartLoop();
	
private:
	SDL_Window* _main_window = nullptr;
	SDL_Surface* _screen_surface = nullptr;
	SDL_Renderer* _render = nullptr;

	SDL_Color _background_color;

	generic_tools::ds::bsp_tree<std::vector<Control>, int>* _mouse_collision = nullptr;

	int _width = 0;
	int _height = 0;
	int _x = 0;
	int _y = 0;
	uint32_t _flags = 0;
	const char* _title = nullptr;



	int InitGraphics();
	int MainLoop();

	void SetBackgroundColor();

	void Update();

};

