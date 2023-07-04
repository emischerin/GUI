#include "ScrollBarButton.h"
#include "ScrollBar.h"

ScrollBarButton::ScrollBarButton(Triangle::TriangleDirection dir, ScrollBar* parent): Control(parent)
{
	_triangle = new Triangle(&_bounding_rect, dir);
	_triangle->SetDirection(dir);
	_triangle->SetColor(255, 100, 50, 1);
	_triangle->SetBoundingRect(&_bounding_rect);
	_triangle->InitVertices();


	/*This needs only for base dtor correct working*/
	this->AddPrimitive(_triangle);

	
}

void ScrollBarButton::ReactToEvents()
{

}

void ScrollBarButton::Update()
{
	_triangle->InitVertices();

	Triangle::TriangleDirection d = _triangle->GetDirection();

	if (d == Triangle::TriangleDirection::UP) {
		int x = _parent_control->GetX();
		int y = _parent_control->GetY();

		this->SetBoundingRect(x, y, this->GetWidth(),this->GetHeight());

		_triangle->SetBoundingRect(&_bounding_rect);


		return;
	}

	if (d == Triangle::TriangleDirection::DOWN) {
		int x = (_parent_control->GetX() + _parent_control->GetWidth()) - this->GetWidth();
		int y = (_parent_control->GetY() + _parent_control->GetHeight()) - this->GetHeight();

		this->SetBoundingRect(x, y, this->GetWidth(), this->GetHeight());

		_triangle->SetBoundingRect(&_bounding_rect);

		return;
	}

	
}

void ScrollBarButton::Draw()
{
	CollisionDetector cd;

	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_color.r, _mouse_over_color.g, _mouse_over_color.b, _mouse_over_color.a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		
		_triangle->Draw();

	}
	else {
		
		SDL_SetRenderDrawColor(AppGlobals::main_render, _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		
		_triangle->Draw();

	}
		
}
