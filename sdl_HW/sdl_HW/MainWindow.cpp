#include "MainWindow.h"
MainWindow::MainWindow(int width, int height,const char* w_title)
{
	if (width <= 0) return;
	if (height <= 0) return;

	this->_width = width;
	this->_height = height;
	this->_title = w_title;

	this->_mouse_collision = new generic_tools::ds::bsp_tree<std::vector<Control>, int>(_width, _height, 6);

	this->SetBackgroundColor();

	
	
	
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

	
	_win_ptr = SDL_CreateWindow(_title, _x, _y,
		_width, _height, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_VULKAN);

	if (!_win_ptr) {
		_win_ptr = SDL_CreateWindow(_title, _x, _y,
			_width, _height, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL);
	}
	
	if (!_win_ptr) return -1;

	SDL_SetWindowResizable(_win_ptr, SDL_TRUE);

	
	/*_header = new Header(_win_ptr, 35,35);
	_header->SetColor(213, 229, 245, 1);
	_header->SetParentWindow(_win_ptr);*/
	_win_render = SDL_CreateRenderer(_win_ptr, -1, SDL_RENDERER_ACCELERATED);

	
	/*If creating hardware render fails we give a chance to create at least software render*/
	if (!_win_render) {
		_win_render = SDL_CreateRenderer(_win_ptr, -1, SDL_RENDERER_SOFTWARE);
		if (!_win_render) return -1;
	}

	

	return 0;
		
	
}

void MainWindow::SetBackgroundColor()
{
	_background_color.r = 255;
	_background_color.g = 255;
	_background_color.b = 255;
	_background_color.a = 1;
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

		this->Update();
	}
}

void MainWindow::Update()
{
	SDL_SetRenderDrawColor(AppGlobals::main_render, _background_color.r, _background_color.g, _background_color.b, _background_color.a);

	SDL_RenderClear(AppGlobals::main_render);
	//_header->Draw();
	SDL_RenderPresent(AppGlobals::main_render);

	


}

