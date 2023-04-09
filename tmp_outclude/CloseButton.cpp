#include "CloseButton.h"


CloseButton::CloseButton()
{
	_r = 146;
	_g = 7;
	_b = 173;
	_a = 1;
	
	_bounding_rect.x = _x;
	_bounding_rect.y = _y;
	_bounding_rect.w = _width;
	_bounding_rect.h = _height;
}

CloseButton::CloseButton(SDL_Window* parent)
{
	_r = 146;
	_g = 7;
	_b = 173;
	_a = 1;
	_parent_window = parent;
	
	_x = 70;
	_y = 70;

	_bounding_rect.x = _x;
	_bounding_rect.y = _y;
	_bounding_rect.w = _width;
	_bounding_rect.h = _height;
}





void CloseButton::Draw()
{
	int mouse_x, mouse_y;
	int global_mouse_x, global_mouse_y;
	
	CollisionDetector cd;

	
	if (cd.MouseInWindow(_parent_window) && cd.MouseInControl(this)) {
		//if (cd.MouseInWindow(_parent_window)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_r, _mouse_over_g, _mouse_over_b, _mouse_over_a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
		//}
	}
	else {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _r, _g, _b, _a);
		//SDL_RenderDrawRect(_renderer, &_bounding_rect);
		SDL_SetRenderDrawColor(AppGlobals::main_render, 0, 0, 0, 1);
		
	}

	

	/*SDL_RenderDrawLine(_renderer, (_x), (_y), (_x + _width), (_y + _height));
	SDL_RenderDrawLine(_renderer, (_x), (_y + _height), (_x + _width), (_y));*/
	
	SDL_RenderDrawLine(AppGlobals::main_render, (_x + 10), (_y + 10), (_x + _width) - 10, (_y + _height) - 10);
	SDL_RenderDrawLine(AppGlobals::main_render, (_x + 10), (_y + 11), (_x + _width) - 11, (_y + _height) - 10);
	
	//SDL_RenderDrawLine(_renderer, (_x + 1), (_y + _height), (_x + _width) - 1, (_y + _height) - 1);
	SDL_RenderDrawLine(AppGlobals::main_render, (_x + 10), (_y + _height) - 10, (_x + _width) - 10, (_y + 10));
	SDL_RenderDrawLine(AppGlobals::main_render, (_x + 10), (_y + _height) - 11, (_x + _width) - 11, (_y + 10));
	
	
	
}

void CloseButton::SetWidthAndHeight(int w, int h)
{
	_width = w;
	_height = h;
	_bounding_rect.w = w;
	_bounding_rect.h = h;
}

int CloseButton::GetWidth()
{
	return _width;
}

void CloseButton::SetPosition(int x, int y)
{
	_x = x;
	_y = y;
	_bounding_rect.x = x;
	_bounding_rect.y = y;
}


