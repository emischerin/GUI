#include "ResizeButton.h"

ResizeButton::ResizeButton()
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;

	
	this->SetWidthAndHeight(20, 20);
}

ResizeButton::ResizeButton(Control* parent) : Control(parent)
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;


	
}

void ResizeButton::ReactToEvents()
{

}

void ResizeButton::Draw()
{
	CollisionDetector cd;



	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_r, _mouse_over_g, _mouse_over_b, _mouse_over_a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		
	}
	else {
		SDL_Color* parent_color = _parent_control->GetColor();

		SDL_SetRenderDrawColor(AppGlobals::main_render, parent_color->r, parent_color->g, parent_color->b, parent_color->a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);

	}

	SDL_Rect r;
	r.x = GetX() + 10;
	r.y = GetY() + 10;
	r.w = 15;
	r.h = 15;

	SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
	SDL_RenderDrawRect(AppGlobals::main_render, &r);
	SDL_RenderDrawLine(AppGlobals::main_render, r.x, r.y + 1, r.x + r.w - 1, r.y + 1);

	/*if (AppGlobals::app_is_inFullscreen) {

		SDL_Rect r;
		r.x = _x + 5;
		r.y = _y + 5;
		r.w = 5;
		r.h = 5;

		SDL_RenderDrawRect(AppGlobals::main_render, &r);

		SDL_RenderDrawLine(AppGlobals::main_render, r.x + 2, r.y, r.x + 2, r.y - 2);
		SDL_RenderDrawLine(AppGlobals::main_render, r.x + 2, r.y - 2, r.x + 5 + 2, r.y - 2);
		SDL_RenderDrawLine(AppGlobals::main_render, r.x + 2 + 5, r.y - 2, r.x + 5 + 2, r.y + 5);


	}
	else {
		SDL_Rect r;
		r.x = _x + 5;
		r.y = _y + 5;
		r.w = 5;
		r.h = 5;


		SDL_RenderDrawRect(AppGlobals::main_render, &r);
	}*/
}
