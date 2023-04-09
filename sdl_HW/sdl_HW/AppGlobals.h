#pragma once
#include <SDL.h>
#include "MainWindow.h"

class AppGlobals
{
public:

	static SDL_Renderer* render;
	static MainWindow* main_window;
};