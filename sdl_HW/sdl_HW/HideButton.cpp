#include "HideButton.h"

HideButton::HideButton()
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;
}

HideButton::HideButton(Control* parent) : Control(parent)
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;
}

HideButton::HideButton(SDL_Window* parent)
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;
	_parent_window = parent;

}

void HideButton::ReactToEvents()
{

}

void HideButton::Draw()
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

	SDL_Rect r = { _bounding_rect.x + 10,_bounding_rect.y + 16,16,2 };

	SDL_SetRenderDrawColor(AppGlobals::main_render, 255, 255, 255, 1);
	SDL_RenderFillRect(AppGlobals::main_render, &r);
}

void HideButton::SetParentControl(Control* parent)
{
	this->_parent_control = parent;

	SDL_Rect* p_rect = _parent_control->GetBoundingRect();
	p_rect->w -= _bounding_rect.w;
}
