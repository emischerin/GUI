#pragma once
#ifndef APPGLOBALS_H
#define APPGLOBALS_H
#include <SDL.h>
#include <SDL_events.h>


class MainWindow;
class Control;

class AppGlobals
{
public:
	static SDL_Renderer* main_render;
	static SDL_Window* main_window;

	
	static Control* selected_control;
	static MainWindow* my_main_window;
	static SDL_Event* event;
	
	
	


	static bool app_is_inFullscreen;
	

};

#endif
