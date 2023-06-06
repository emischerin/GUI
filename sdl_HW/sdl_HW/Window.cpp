#include "Window.h"


void Window::AddControl(Control* control)
{
	if(!control) return;
	
	_controls.push_back(control);


}

void Window::ReactToEvents()
{
	this->InternalReactToEvents();

	for (int i = 0; i < _controls.size(); ++i) {
		Control* ctrl = _controls[i];
		ctrl->ReactToEvents();
	}
}

void Window::InternalReactToEvents()
{

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

Window::WindowSizeState Window::GetSizeState() const
{
	return _size_state;
}

void Window::SetSizeState(WindowSizeState size_state)
{
	this->_size_state = size_state;

	switch (_size_state) {
	case MAXIMIZED:
		this->Maximize();
		break;
	case MINIMIZED:
		this->Minimize();
		break;
	case MY_SIZE:
		this->SetMySize();
		break;
	default:
		this->SetMySize();
		break;
	}


}

SDL_Renderer* Window::GetWinRender()
{
	return _win_render;
}

SDL_Window* Window::GetWinPtr()
{
	return _win_ptr;
}

void Window::Resize(int width, int height)
{
	this->_width = width;
	this->_height = height;

	SDL_SetWindowSize(_win_ptr, _width, _height);
}

void Window::Maximize()
{
	SDL_MaximizeWindow(_win_ptr);
}

void Window::Minimize()
{
	SDL_MinimizeWindow(_win_ptr);
}

void Window::SetMySize()
{
	SDL_SetWindowSize(_win_ptr, _width, _height);
}