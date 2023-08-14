#include "ScrollBarCaret.h"
#include "Scene.h"

ScrollBarCaret::ScrollBarCaret(BaseScrollBar* parent) : Control(parent)
{
	if (!parent) return;

	_scrollbar = parent;
}



void ScrollBarCaret::ReactToEvents()
{

}

void ScrollBarCaret::Update()
{
	
}

void ScrollBarCaret::Draw()
{
	CollisionDetector cd;

	

	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_color.r, _mouse_over_color.g, _mouse_over_color.b, _mouse_over_color.a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		

	}
	else {

		SDL_SetRenderDrawColor(AppGlobals::main_render, _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		

	}
}