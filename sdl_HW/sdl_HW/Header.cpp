#include "Header.h"

Header::Header(SDL_Window* w,int rel_y)
{
	if (!w) return;

	_rel_y = rel_y;
	
	_border_line.SetRelativeHeight(rel_y);
	_close_button.SetWidthAndHeight(rel_y - 1,17);
	_parent_window = w;
	

}

void Header::ImplBehaviour()
{
	this->DrawHeaderRect();
	

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

}