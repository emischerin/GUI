#include "Window.h"
#include "Header.h"
#include "Menu.h"


Window::Window(int width, int height,const char* title)
{
	_width = width;
	_height = height;
	_title = title;
	
}

Window::Window(int x, int y, int width, int height, const char* title)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_title = title;
}

void Window::AddControl(Control* control)
{
	if(!control) return;
	
	_controls.push_back(control);

	control->SetParentWindow(this);

}

void Window::AddPrimitive(Primitive* primitive)
{
	if (!primitive) return;

	_primitives.push_back(primitive);

	primitive->SetParentWindow(this);
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

void Window::Update()
{
	this->InternalReactToEvents();

	for (int i = 0; i < _controls.size(); ++i) {
		Control* ctrl = _controls[i];
		if(ctrl) ctrl->Update();
	}

	for (int i = 0; i < _primitives.size(); ++i) {
		Primitive* p = _primitives[i];
		if(p) p->Update();
	}
}

void Window::InternalUpdate()
{

}

void Window::PreDraw()
{
	for (int i = 0; i < _controls.size(); ++i) {
		Control* ctrl = _controls[i];
		if (ctrl) ctrl->PreDraw();
	}
}

void Window::Draw()
{
	int set_rndr_target = SDL_SetRenderTarget(_win_render, _texture);

	if (set_rndr_target == 0) { /*No errors, we can render to texture safely*/
		_render_to_texture = true;
	}
	else { _render_to_texture = false; }
	

	SDL_SetRenderDrawColor(_win_render, _background_color.r, _background_color.g, _background_color.b, _background_color.a);

	SDL_RenderClear(_win_render);



	for (int i = 0; i < _controls.size(); ++i) {
		Control* ctrl = _controls[i];
		if(ctrl) ctrl->Draw();
	}
	
	SDL_SetRenderTarget(_win_render, 0);

	SDL_RenderCopy(_win_render, _texture, 0, 0);

	SDL_RenderPresent(_win_render);

	
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

	if (_header) {
		delete _header;
		_controls.erase(_controls.begin() + _header_index);
				
	}
		
	_header = head;
	this->AddControl(head);
	_header_index = _controls.size() - 1;

	SDL_SetWindowHitTest(_win_ptr, Window::MoveWindowCallback, 0);
}

void Window::GetWindowSizeAsRect(SDL_Rect* rect) const
{
	if (!rect) return;

	rect->x = this->_x;
	rect->y = this->_y;
	rect->w = this->_width;
	rect->h = this->_height;
}

void Window::AddMenu(Menu* menu)
{
	if (_menu) {
		delete _menu;
		_controls.erase(_controls.begin() + _menu_index);
	}

	_menu = menu;
	this->AddControl(menu);
	_menu_index = _controls.size() - 1;
	
}

int Window::GetHeaderHeight() 
{
	if (this->HasHeader())
		return _header->GetHeight();

	return 0;
}

int Window::GetMenuWidth() 
{
	if (this->HasMenu())
		return _menu->GetWidth();

	return 0;
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
	_width = display.w;
	_height = display.h;
	//SDL_GetDisplayBounds()
	//SDL_MaximizeWindow(_win_ptr);
	this->_size_state = MAXIMIZED;
	this->TryReallocateTexture();
}

void Window::Minimize()
{
	this->CaptureWindowState();
	SDL_MinimizeWindow(_win_ptr);
	this->_size_state = MINIMIZED;
}

void Window::SetMySize()
{
	
	SDL_SetWindowSize(_win_ptr, _saved_width, _saved_height);
	SDL_SetWindowPosition(_win_ptr, _saved_x, _saved_y);
	this->_size_state = MY_SIZE;
	_width = _saved_width;
	_height = _saved_height;
	this->TryReallocateTexture();
	
}

int Window::GetWinHeight() const
{
	return _height;
}

int Window::GetWinWidth() const
{
	return _width;
}

void Window::CaptureWindowState()
{
	SDL_GetWindowPosition(_win_ptr, &_saved_x, &_saved_y);
	SDL_GetWindowSize(_win_ptr, &_saved_width, &_saved_height);
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

bool Window::HasMenu() const
{
	return _menu != nullptr;
}

void Window::TryReallocateTexture()
{
	if (this->TextureReallocationNeeded()) {
		SDL_DestroyTexture(_texture);

		_texture = SDL_CreateTexture(_win_render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
			_width, _height);


	}
	
}

bool Window::TextureReallocationNeeded()
{
	if (!_texture) return false;

	int t_width, t_height;

	int texture_query_result = SDL_QueryTexture(_texture, 0, 0, &t_width, &t_height);

	if (texture_query_result > 0) return false;

	if ((t_width != this->_width) && (t_height != this->_height)) {
		return true;
	}

	return false;
}

SDL_Texture* Window::GetWindowTexture() const
{
	return _texture;
}

int Window::GetMyPitch()
{
	return 0;
}

Window::~Window()
{
	if (_texture)
		SDL_DestroyTexture(_texture);
}
