#include "CloseButton.h"


CloseButton::CloseButton()
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;
	
	
	
	
}

CloseButton::CloseButton(Control* parent) : Control(parent)
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;

	
}


CloseButton::CloseButton(SDL_Window* parent)
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;
	_parent_window = parent;
	


}


void CloseButton::ReactToEvents()
{
	CollisionDetector cd;

	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		
		if (!AppGlobals::event) return;

		uint32_t event_t = AppGlobals::event->type;

		

		if (event_t == SDL_MOUSEBUTTONDOWN) {
			Uint8 mouse_btn_code = AppGlobals::event->button.button;
			if (mouse_btn_code == 1) { /*Left mouse button*/
				SDL_Quit();
				AppGlobals::quit_requested = true;
				

			}
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
		
		//}
	}
	else {
		SDL_Color* parent_color = _parent_control->GetColor();

		SDL_SetRenderDrawColor(AppGlobals::main_render, parent_color->r, parent_color->g, parent_color->b, parent_color->a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		
		
	}

	
	SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
	/*SDL_RenderDrawLine(_renderer, (_x), (_y), (_x + _width), (_y + _height));
	SDL_RenderDrawLine(_renderer, (_x), (_y + _height), (_x + _width), (_y));*/
	
	SDL_RenderDrawLine(AppGlobals::main_render, (GetX() + 10), (GetY() + 10), (GetX() + GetWidth() - 10), (GetY() + GetHeight() - 10));
	SDL_RenderDrawLine(AppGlobals::main_render, (GetX() + 10), (GetY() + 11), (GetX() + GetWidth() - 11), (GetY() + GetHeight() - 10));
	
	//SDL_RenderDrawLine(_renderer, (_x + 1), (_y + _height), (_x + _width) - 1, (_y + _height) - 1);
	SDL_RenderDrawLine(AppGlobals::main_render, (GetX() + 10), (GetY() + GetHeight() - 10), (GetX() + GetWidth() - 10), (GetY() + 10));
	SDL_RenderDrawLine(AppGlobals::main_render, (GetX()+ 10), (GetY()+ GetHeight() - 11), (GetX() + GetWidth() - 11), (GetY() + 10));
	
	
	
}

void CloseButton::SetParentControl(Control* parent)
{
	this->_parent_control = parent;

	SDL_Rect* p_rect = _parent_control->GetBoundingRect();
	p_rect->w -= _bounding_rect.w;
}






