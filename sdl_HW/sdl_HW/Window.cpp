#include "Window.h"


void Window::AddControl(Control* control)
{
	if(!control) return;
	if (!_mouse_collision) return;

	std::vector<Control*>* tmp = _mouse_collision->Search(control->GetX(),control->GetY());


}


SDL_Renderer* Window::GetWinRender()
{
	return _win_render;
}

SDL_Window* Window::GetWinPtr()
{
	return _win_ptr;
}