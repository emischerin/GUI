#include "Header.h"

Header::Header(int height,int buttons_width)
{
	

	_height = height;
	
	_close_button.SetWidthAndHeight(height,buttons_width);
	_resize_button.SetWidthAndHeight(height, buttons_width);

	_close_button.SetParentControl(this);
	_resize_button.SetParentControl(this);
	
	_sys_btns_width = buttons_width;

	SDL_GetWindowPosition(AppGlobals::main_window, &_bounding_rect.x, &_bounding_rect.y);
	SDL_GetWindowSize(AppGlobals::main_window, &_bounding_rect.w, &_bounding_rect.h);

}


void Header::ReactToEvents()
{
	
		
			

	_close_button.ReactToEvents();
	_resize_button.ReactToEvents();
}

void Header::MoveWindow()
{
	
			
			
			
			
	
}

void Header::Draw()
{
	this->DrawHeaderRect();
	
	//_border_line.Draw();
	DrawCloseButton();
	DrawResizeButton();

}

void Header::DrawHeaderRect()
{
	int x, y;

	SDL_GetWindowSize(AppGlobals::main_window, &x, &y);
	if (AppGlobals::main_render) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _color.r, _color.g, _color.b, _color.a);
		
		this->SetBoundingRect(0, 0, x - _sys_btns_width * 2,_height);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		
	}
}

void Header::DrawCloseButton()
{
	int x, y,close_button_offset_r;

	SDL_GetWindowSize(AppGlobals::main_window, &x, &y);
	if (AppGlobals::main_render) {
		close_button_offset_r = x - _close_button.GetWidth();
		_close_button.SetPosition(close_button_offset_r, 0);
		
		_close_button.Draw();

	}
}

void Header::DrawResizeButton()
{
	int x, y, resize_button_offset;
	SDL_GetWindowSize(AppGlobals::main_window, &x, &y);
	if (AppGlobals::main_render) {
		resize_button_offset = x - _close_button.GetWidth() - _resize_button.GetWidth();
		_resize_button.SetPosition(resize_button_offset, 0);
		_resize_button.Draw();
	}

}

