#include "MainWindow.h"
MainWindow::MainWindow(int width, int height,const char* w_title)
{
	if (width <= 0) return;
	if (height <= 0) return;

	this->_width = width;
	this->_height = height;
	this->_title = w_title;
	
}

int MainWindow::StartLoop()
{
	int init = this->InitGraphics();

	if (init < 0) return init;

	return MainLoop();

}

int MainWindow::InitGraphics()
{
	int sdl_init = SDL_Init(SDL_INIT_VIDEO);

	if (sdl_init < 0) return sdl_init;

	SDL_DisplayMode dm;

	int display_mode = SDL_GetCurrentDisplayMode(0, &dm);

	if (display_mode != 0) return display_mode;

	this->_x = dm.w / 4;
	this->_y = dm.h / 4;

	
	_main_window = SDL_CreateWindow(_title, _x, _y,
		_width, _height, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);

	if (!_main_window) return -1;

	_render = SDL_CreateRenderer(_main_window, -1, SDL_RENDERER_ACCELERATED);
	/*If creating hardware render fails we give a chance to create at least software render*/
	if (!_render) {
		_render = SDL_CreateRenderer(_main_window, -1, SDL_RENDERER_SOFTWARE);
		if (!_render) return -1;
	}

	return 0;
		
	
}

int MainWindow::MainLoop()
{
	SDL_Event e;
	bool q = false;

	for (;;) {
		while (SDL_PollEvent(&e)) {
			uint32_t event_t = e.type;
			if (event_t == SDL_QUIT) return 1;
			
		}
	}
}