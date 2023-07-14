#include "ScrollBarButton.h"
#include "BaseScrollBar.h"

ScrollBarButton::ScrollBarButton(Triangle::TriangleDirection dir, BaseScrollBar* parent): Control(parent)
{
	if (!parent) return;

	_scroll_bar = parent;

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

		int width = this->GetWidth();
		int height = this->GetHeight();

		this->SetBoundingRect(x, y,width,height);

		_triangle->SetBoundingRect(x+5,y+5, width/2,height/2);

		


		return;
	}

	if (d == Triangle::TriangleDirection::DOWN) {

		int x = (_parent_control->GetX() + _parent_control->GetWidth()) - this->GetWidth();
		int y = (_parent_control->GetY() + _parent_control->GetHeight()) - this->GetHeight();
		int width = this->GetWidth();
		int height = this->GetHeight();


		this->SetBoundingRect(x, y, width, height);

		_triangle->SetBoundingRect(x + 5, y + 5, width / 2, height / 2);

		return;
	}

	
}

void ScrollBarButton::Draw()
{
	CollisionDetector cd;

	if (cd.MouseInWindow(AppGlobals::main_window) && cd.MouseInControl(this)) {
		SDL_SetRenderDrawColor(AppGlobals::main_render, _mouse_over_color.r, _mouse_over_color.g, _mouse_over_color.b, _mouse_over_color.a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		_triangle->SetColor(255,255,255, 1);
		_triangle->Draw();

	}
	else {
		
		SDL_SetRenderDrawColor(AppGlobals::main_render, _color.r, _color.g, _color.b, _color.a);
		SDL_RenderFillRect(AppGlobals::main_render, &_bounding_rect);
		_triangle->SetColor(228, 209, 230, 1);
		_triangle->Draw();

	}
		
}
