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

	
	_main_window = SDL_CreateWindow(_title, _x, _y,
		_width, _height, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);

	if (!_main_window) return -1;

	SDL_SetWindowResizable(_main_window, SDL_TRUE);

	this->_test_border = new BorderLine(_main_window, 0, 50);
	_test_border->SetColor(134, 8, 196, 1);

	this->_test_button = new CloseButton(_main_window);


	/*
	*	Leads to incorrect bounding box Behaviour. Bounding Rect coordinates are different from the
	* actual button coordinates. THEY MUST BE THE SAME!
	* 	_test_button->SetPosition(100, 100);
	* 
	* 
	*/
	

	_render = SDL_CreateRenderer(_main_window, -1, SDL_RENDERER_ACCELERATED);

	this->_test_border->SetRenderer(_render);
	this->_test_button->SetRenderer(_render);
	/*If creating hardware render fails we give a chance to create at least software render*/
	if (!_render) {
		_render = SDL_CreateRenderer(_main_window, -1, SDL_RENDERER_SOFTWARE);
		if (!_render) return -1;
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
	SDL_SetRenderDrawColor(_render, _background_color.r, _background_color.g, _background_color.b, _background_color.a);

	SDL_RenderClear(_render);
	_test_border->ImplBehaviour();
	_test_button->ImplBehaviour();
	SDL_RenderPresent(_render);

	


}

SDL_Window* MainWindow::GetWinPtr()
{
	return _main_window;
}

SDL_Renderer* MainWindow::GetWinRender()
{
	return _render;
}