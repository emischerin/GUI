#include "ResizeButton.h"

ResizeButton::ResizeButton()
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

void ResizeButton::ReactToEvents()
{

}

void ResizeButton::Draw()
{
	CollisionDetector cd;



	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_r, _mouse_over_g, _mouse_over_b, _mouse_over_a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
	}
	else {
		SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);

	}

	if (AppGlobals::app_is_inFullscreen) {

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
	}
}
