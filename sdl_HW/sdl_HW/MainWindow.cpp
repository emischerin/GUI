#include "MainWindow.h"
MainWindow::MainWindow(int width, int height,const char* w_title)
{
	if (width <= 0) return;
	if (height <= 0) return;

	this->_width = width;
	this->_height = height;
	this->_title = w_title;

	Header* h = new Header(35, 35);
	h->SetColor(62, 19, 66, 1);
	
	this->AddControl(h);
	

	this->SetBackgroundColor();


	AppGlobals::my_main_window = this;
	
	
	
}

int MainWindow::StartLoop(MainWindow::LoopType loop_type)
{
	int init = this->InitGraphics();

	if (init < 0) return init;

	if (loop_type == HARD_REAL_TIME)
		return HardRealTimeMainLoop();
	else return SimpleAppMainLoop();
	

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

	
	
	_win_render = SDL_CreateRenderer(_win_ptr, -1, SDL_RENDERER_ACCELERATED);

	
	/*If creating hardware render fails we give a chance to create at least software render*/
	if (!_win_render) {
		_win_render = SDL_CreateRenderer(_win_ptr, -1, SDL_RENDERER_SOFTWARE);
		if (!_win_render) return -1;
	}

	AppGlobals::main_render = _win_render;
	AppGlobals::main_window = _win_ptr;

	return 0;
		
	
}

void MainWindow::SetBackgroundColor()
{
	_background_color.r = 255;
	_background_color.g = 255;
	_background_color.b = 255;
	_background_color.a = 1;
}

int MainWindow::HardRealTimeMainLoop()
{
	SDL_Event e;
	bool q = false;

	

	for (;;) {
		while (SDL_PollEvent(&e)) {
			uint32_t event_t = e.type;

			if (event_t == SDL_QUIT) return 1;
			if (event_t == SDL_WINDOWEVENT) AppGlobals::window_event = &e.window;
			if (event_t == SDL_MOUSEMOTION) AppGlobals::mouse_motion = &e.motion;
			
			if (event_t == SDL_MOUSEBUTTONDOWN) AppGlobals::mouse_button_code = e.button.button;
			
			if (event_t == SDL_KEYDOWN) AppGlobals::keyboard_event = &e.key;

			
		}

		
		this->ReactToEvents();
		this->Draw();
		
		

		
		
	}
}

int MainWindow::SimpleAppMainLoop()
{
	SDL_Event e;
	bool q = false;

	

	for (;;) {
		int wait_result = SDL_WaitEvent(&e);
			uint32_t event_t = e.type;

			/*if (event_t == SDL_QUIT) return 1;
			if (event_t == SDL_WINDOWEVENT) AppGlobals::window_event = &e.window;
			if (event_t == SDL_MOUSEMOTION) AppGlobals::mouse_motion = &e.motion;

			if (event_t == SDL_MOUSEBUTTONDOWN) AppGlobals::mouse_button_code = e.button.button;

			if (event_t == SDL_KEYDOWN) AppGlobals::keyboard_event = &e.key;*/

			if (wait_result) AppGlobals::event = &e;

			this->ReactToEvents();
			this->Draw();

		


		
		
		
		



	}

	

}

MainWindow::WindowSizeState MainWindow::GetSizeState() const
{
	return _size_state;
}

MainWindow::WindowSizeState MainWindow::SetSizeState(MainWindow::WindowSizeState size_state)
{
	this->_size_state = size_state;

	switch (_size_state) {
	case MAXIMIZED:
		this->Maximize();
		break;
	case MINIMIZED:
		this->Minimize();
		break;
	case MY_SIZE:
		this->SetMySize();
		break;
	default:
		this->SetMySize();
		break;
	}


}

void MainWindow::Maximize()
{

}

void MainWindow::Minimize()
{

}

void MainWindow::SetMySize()
{

}