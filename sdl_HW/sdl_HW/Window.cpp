#include "Window.h"

SDL_Renderer* Window::GetWinRender()
{
	return _win_render;
}

SDL_Window* Window::GetWinPtr()
{
	return _win_ptr;
}