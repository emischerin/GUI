#include "Header.h"

Header::Header(SDL_Window* w,int rel_y)
{
	if (!w) return;

	_rel_y = rel_y;
	
	_border_line.SetRelativeHeight(rel_y);
	_close_button.SetWidthAndHeight(rel_y - 1,34);
	_parent_window = w;
	

}

void Header::ImplBehaviour()
{
	this->DrawHeaderRect();
	_border_line.ImplBehaviour();
	DrawCloseButton();

}

void Header::DrawHeaderRect()
{
	int x, y;

	SDL_GetWindowSize(_parent_window, &x, &y);
	if (_renderer) {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		
		this->SetBoundingRect(0, 0, x, _rel_y);
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
		_close_button.ImplBehaviour();

	}
}

void Header::SetParentWindow(SDL_Window* w)
{
	this->_parent_window = w;
	_close_button.SetParentWindow(w);
	_border_line.SetParentWindow(w);
}