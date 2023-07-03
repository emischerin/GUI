#include "ScrollBarButton.h"
#include "ScrollBar.h"

ScrollBarButton::ScrollBarButton(Triangle::TriangleDirection dir, ScrollBar* parent): Control(parent)
{
	_triangle = new Triangle(&_bounding_rect, dir);
	_triangle->SetDirection(dir);
	_triangle->SetColor(255, 100, 50, 1);
	_triangle->SetBoundingRect(&_bounding_rect);
	_triangle->InitVertices();


	
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
		_triangle->InitVertices();
		_triangle->Draw();

	}
	else {
		
		SDL_SetRenderDrawColor(AppGlobals::main_render, _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		_triangle->InitVertices();
		_triangle->Draw();

	}
		
}
