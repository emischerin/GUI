#include "ScrollBarButton.h"

ScrollBarButton::ScrollBarButton(Triangle::TriangleDirection dir)
{
	_triangle.SetDirection(dir);
}

void ScrollBarButton::ReactToEvents()
{

}

void ScrollBarButton::Draw()
{
	CollisionDetector cd;

	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_color.r, _mouse_over_color.g, _mouse_over_color.b, _mouse_over_color.a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		_triangle.Draw();

	}
	else {
		SDL_Color* parent_color = _parent_control->GetColor();

		SDL_SetRenderDrawColor(AppGlobals::main_render, parent_color->r, parent_color->g, parent_color->b, parent_color->a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		_triangle.Draw();

	}
		
}
