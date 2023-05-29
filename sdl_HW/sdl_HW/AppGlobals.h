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
	static SDL_ControllerTouchpadEvent* touchpad_event;
	static SDL_KeyboardEvent* keyboard_event;
	static Uint8 mouse_button_code;
	static Control* selected_control;

	static bool app_is_inFullscreen;
	

};

