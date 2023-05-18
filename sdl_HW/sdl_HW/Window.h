#pragma once
#include <vector>
#include <SDL.h>
#include "AppGlobals.h"
#include "Control.h"


class Window
{
public:

	SDL_Renderer* GetWinRender();
	SDL_Window* GetWinPtr();
	void AddControl(Control* control);

	void Draw();

protected:
	SDL_Renderer* _win_render = nullptr;
	SDL_Window* _win_ptr = nullptr;
	
	SDL_Color _background_color;
	std::vector<Control*> _controls;
	int _width = 0;
	int _height = 0;
	int _x = 0;
	int _y = 0;
	uint32_t _flags = 0;
	const char* _title = nullptr;
};