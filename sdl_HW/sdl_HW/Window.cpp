#include "Window.h"


void Window::AddControl(Control* control)
{
	if(!control) return;
	
	_controls.push_back(control);


}

void Window::Draw()
{
	SDL_SetRenderDrawColor(AppGlobals::main_render, _background_color.r, _background_color.g, _background_color.b, _background_color.a);

	SDL_RenderClear(AppGlobals::main_render);

	for (int i = 0; i < _controls.size(); ++i) {
		Control* ctrl = _controls[i];
		ctrl->Draw();
	}

	SDL_RenderPresent(AppGlobals::main_render);

	
}

SDL_Renderer* Window::GetWinRender()
{
	return _win_render;
}

SDL_Window* Window::GetWinPtr()
{
	return _win_ptr;
}