#pragma once
#include <SDL.h>
#include <SDL_events.h>
#include "Control.h"

class AppGlobals
{
public:
	static SDL_Renderer* main_render;
	static SDL_Window* main_window;
	static SDL_WindowEvent* window_event;
	static SDL_MouseMotionEvent* mouse_motion;
	static SDL_MouseButtonEvent* mouse_button;
	static SDL_KeyboardEvent* keyboard_event;

	static Control* selected_control;
	

};

