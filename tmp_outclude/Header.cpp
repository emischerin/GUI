#include "Header.h"

Header::Header(SDL_Window* w,int height,int buttons_width)
{
	if (!w) return;

	_height = height;

	
	
	_close_button.SetWidthAndHeight(height,buttons_width);
	_parent_window = w;
	
	

	

}

void Header::Draw()
{
	this->DrawHeaderRect();
	
	//_border_line.Draw();
	DrawCloseButton();

}

void Header::DrawHeaderRect()
{
	int x, y;

	SDL_GetWindowSize(_parent_window, &x, &y);
	if (AppGlobals::main_render) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _r, _g, _b, _a);
		
		this->SetBoundingRect(0, 0, x, _height);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		
	}
}

void Header::DrawCloseButton()
{
	int x, y,close_button_offset_r;

	SDL_GetWindowSize(_parent_window, &x, &y);
	if (AppGlobals::main_render) {
		close_button_offset_r = x - _close_button.GetWidth();
		_close_button.SetPosition(close_button_offset_r, 0);
		
		_close_button.Draw();

	}
}

