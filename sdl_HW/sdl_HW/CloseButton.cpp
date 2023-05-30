#include "CloseButton.h"


CloseButton::CloseButton()
{
	_r = 146;
	_g = 7;
	_b = 173;
	_a = 1;
	
	this->SetWidthAndHeight(20, 20);
	
	
}

CloseButton::CloseButton(Control* parent) : Control(parent)
{
	_r = 146;
	_g = 7;
	_b = 173;
	_a = 1;

	this->SetWidthAndHeight(20, 20);
}

CloseButton::CloseButton(SDL_Window* parent)
{
	_r = 146;
	_g = 7;
	_b = 173;
	_a = 1;
	_parent_window = parent;
	


}


void CloseButton::ReactToEvents()
{
	CollisionDetector cd;

	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		
		

	
			Uint8 mouse_click = AppGlobals::mouse_button_code;
			if (mouse_click == 1) { /*Left mouse button*/
				SDL_Quit();
				
			}
	

	

		
	}
	
}


void CloseButton::Draw()
{
	int mouse_x, mouse_y;
	int global_mouse_x, global_mouse_y;
	
	CollisionDetector cd;

	
	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		//if (cd.MouseInWindow(_parent_window)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_r, _mouse_over_g, _mouse_over_b, _mouse_over_a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
		//}
	}
	else {
		//SDL_SetRenderDrawColor(AppGlobals::main_render, _r, _g, _b, _a);
		//SDL_RenderDrawRect(_renderer, &_bounding_rect);
		SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
		
	}

	

	/*SDL_RenderDrawLine(_renderer, (_x), (_y), (_x + _width), (_y + _height));
	SDL_RenderDrawLine(_renderer, (_x), (_y + _height), (_x + _width), (_y));*/
	
	SDL_RenderDrawLine(AppGlobals::main_render, (GetX() + 10), (GetY() + 10), (GetX() + GetWidth() - 10), (GetY() + GetHeight() - 10));
	SDL_RenderDrawLine(AppGlobals::main_render, (GetX() + 10), (GetY() + 11), (GetX() + GetWidth() - 11), (GetY() + GetHeight() - 10));
	
	//SDL_RenderDrawLine(_renderer, (_x + 1), (_y + _height), (_x + _width) - 1, (_y + _height) - 1);
	SDL_RenderDrawLine(AppGlobals::main_render, (GetX() + 10), (GetY() + GetHeight() - 10), (GetX() + GetWidth() - 10), (GetY() + 10));
	SDL_RenderDrawLine(AppGlobals::main_render, (GetX()+ 10), (GetY()+ GetHeight() - 11), (GetX() + GetWidth() - 11), (GetY() + 10));
	
	
	
}







