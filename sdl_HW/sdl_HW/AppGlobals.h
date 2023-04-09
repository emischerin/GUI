#pragma once
#include <SDL.h>
#include "Window.h"
#include "MainWindow.h"
#include <map>

class AppGlobals
{
protected:
	

public:

	
	static MainWindow* main_window;

	static SDL_Renderer* GetWindowRenderer(const Window* w) 
	{
		return w->GetWinRender();
	}
	
};