#pragma once
#include <SDL.h>
#include <SDL_events.h>
#include "Control.h"

class MainWindow;

class AppGlobals
{
public:
	static SDL_Renderer* main_render;
	static SDL_Window* main_window;

	
	static Control* selected_control;
	static MainWindow* my_main_window;
	static SDL_Event* event;
	static int mouse_x_prev;
	static int mouse_y_prev;
	


	static bool app_is_inFullscreen;
	

};

