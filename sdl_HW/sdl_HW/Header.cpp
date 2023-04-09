#include "Header.h"

Header::Header(SDL_Window* w,int height,int buttons_width)
{
	if (!w) return;

	_height = height;

	
	_border_line.SetParentWindow(w);
	_border_line.SetRelativeHeight(height);
	_border_line.SetColor(0, 0, 0, 0);
	_close_button.SetWidthAndHeight(height - 1,buttons_width);
	_parent_window = w;
	
	

	

}

void Header::Draw()
{
	this->DrawHeaderRect();
	_border_line.SetRenderer(_renderer);
	_border_line.Draw();
	DrawCloseButton();

}

void Header::DrawHeaderRect()
{
	int x, y;

	SDL_GetWindowSize(_parent_window, &x, &y);
	if (_renderer) {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		
		this->SetBoundingRect(0, 0, x, _height);
		SDL_RenderFillRect(_renderer, &_bounding_rect);
		
	}
}

void Header::DrawCloseButton()
{
	int x, y,close_button_offset_r;

	SDL_GetWindowSize(_parent_window, &x, &y);
	if (_renderer) {
		close_button_offset_r = x - _close_button.GetWidth();
		_close_button.SetPosition(close_button_offset_r, 0);
		_close_button.SetRenderer(_renderer);
		_close_button.Draw();

	}
}

void Header::SetParentWindow(SDL_Window* w)
{
	this->_parent_window = w;
	_close_button.SetParentWindow(w);
	_border_line.SetParentWindow(w);
}