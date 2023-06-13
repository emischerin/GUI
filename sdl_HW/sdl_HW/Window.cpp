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

Header* Window::GetHeader()
{
	return _header;
}

void Window::SetHeader(Header* head)
{
	if (!head) return;

	_header = head;
	this->AddControl(head);

	SDL_SetWindowHitTest(_win_ptr, Window::MoveWindowCallback, 0);
}

void Window::Resize(int width, int height)
{
	this->_width = width;
	this->_height = height;

	SDL_SetWindowSize(_win_ptr, _width, _height);
}

void Window::Maximize()
{
	this->CaptureWindowState();
	int win_x, win_y;

	SDL_GetWindowPosition(_win_ptr, &win_x, &win_y);

	SDL_Rect display;
	SDL_Point win_location = { win_x,win_y };
	int display_index = SDL_GetPointDisplayIndex(&win_location);
	
	SDL_GetDisplayBounds(display_index, &display);
	SDL_SetWindowPosition(_win_ptr,display.x,display.y);
	SDL_SetWindowSize(_win_ptr, display.w, display.h);
	//SDL_GetDisplayBounds()
	//SDL_MaximizeWindow(_win_ptr);
	this->_size_state = MAXIMIZED;
}

void Window::Minimize()
{
	this->CaptureWindowState();
	SDL_MinimizeWindow(_win_ptr);
	this->_size_state = MINIMIZED;
}

void Window::SetMySize()
{
	SDL_SetWindowSize(_win_ptr, _width, _height);
	SDL_SetWindowPosition(_win_ptr, _saved_x, _saved_y);
	this->_size_state = MY_SIZE;
}

void Window::CaptureWindowState()
{
	SDL_GetWindowPosition(_win_ptr, &_saved_x, &_saved_y);
	SDL_GetWindowSize(_win_ptr, &_x, &_y);
}

SDL_HitTestResult SDLCALL Window::MoveWindowCallback(SDL_Window* win, const SDL_Point* area, void* data)
{
	CollisionDetector cd;

	Window* w = AppGlobals::win_tracker->GetMyWindow(win);
	if (!w) return SDL_HITTEST_NORMAL;
	Header* h = w->GetHeader();
	if (!h) return SDL_HITTEST_NORMAL;


	
	
	if (cd.MouseInWindow(win) && cd.MouseInControl(h)) {
		if(cd.PointInRect(h->GetBoundingRect(),area->x,area->y))
			return SDL_HITTEST_DRAGGABLE;
	}

		

	return SDL_HITTEST_NORMAL;


}

bool Window::HasHeader() const
{
	return _header != nullptr;
}