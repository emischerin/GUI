#pragma once
#ifndef APPGLOBALS_H
#define APPGLOBALS_H
#include <SDL.h>
#include <SDL_events.h>
#include "WindowTracker.h"

class MainWindow;
class Control;

class AppGlobals
{
public:
	static SDL_Renderer* main_render;
	static SDL_Window* main_window;

	
	static Control* selected_control;
	static MainWindow* my_main_window;

	static WindowTracker* win_tracker;
	static SDL_Event* event;
	
	
	


	static bool app_is_inFullscreen;
	
	static bool quit_requested;

};

#endif
