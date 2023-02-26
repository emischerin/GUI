#include "CloseButton.h"


CloseButton::CloseButton()
{
	_r = 146;
	_g = 7;
	_b = 173;
	_a = 1;
	

	_x = 70;
	_y = 70;

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
	_parent = parent;
	
	_x = 70;
	_y = 70;

	_bounding_rect.x = _x;
	_bounding_rect.y = _y;
	_bounding_rect.w = _width;
	_bounding_rect.h = _height;
}





void CloseButton::ImplBehaviour()
{
	int mouse_x, mouse_y;
	
	
	SDL_GetMouseState(&mouse_x, &mouse_y);

	if (MouseInButton(mouse_x, mouse_y)) {
		SDL_SetRenderDrawColor(_renderer, _mouse_over_r, _mouse_over_g, _mouse_over_b, _mouse_over_a);
		SDL_RenderFillRect(_renderer, &_bounding_rect);
		SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 1);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		//SDL_RenderDrawRect(_renderer, &_bounding_rect);
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 1);
		
	}

	

	
	
	SDL_RenderDrawLine(_renderer, (_x + 10), (_y + 10), (_x + _width) - 10, (_y + _height) - 10);
	SDL_RenderDrawLine(_renderer, (_x + 10), (_y + 11), (_x + _width) - 11, (_y + _height) - 10);
	//SDL_RenderDrawLine(_renderer, (_x + 1), (_y + _height), (_x + _width) - 1, (_y + _height) - 1);
	SDL_RenderDrawLine(_renderer, (_x + 10), (_y + _height) - 10, (_x + _width) - 10, (_y + 10));
	SDL_RenderDrawLine(_renderer, (_x + 10), (_y + _height) - 11, (_x + _width) - 11, (_y + 10));
	
	
}

void CloseButton::SetWidthAndHeight(int w, int h)
{
	_width = w;
	_height = h;
}

bool CloseButton::MouseInButton(int x,int y)
{
	

	return (MouseXInButtonRange(x)) && (MouseYInButtonRange(y));

	
}

bool CloseButton::MouseYInButtonRange(int y)
{
	if ((y >= _y) && (y<= _y + _height))
		return true;

	return false;
}

bool CloseButton::MouseXInButtonRange(int x)
{
	if ((x >= _x ) && (x <= _x + _width))
		return true;

	return false;
}