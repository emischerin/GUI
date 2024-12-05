#include "ScrollBarButton.h"
#include "BaseScrollBar.h"

ScrollBarButton::ScrollBarButton(Triangle::TriangleDirection dir, BaseScrollBar* parent): Control(parent)
{
	if (!parent) return;

	_scroll_bar = parent;
	this->SetParentControl(parent);
	_triangle = new Triangle(&_bounding_rect, dir);
	_triangle->SetDirection(dir);
	_triangle->SetColor(255, 100, 50, 1);
	_triangle->SetBoundingRect(&_bounding_rect);
	_triangle->SetRender(_render);
	_triangle->SetParentControl(this);
	_triangle->InitVertices();


	/*This needs only for base dtor correct working*/
	

	
}



void ScrollBarButton::Update()
{
	

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

	if (d == Triangle::TriangleDirection::LEFT) {

		int x = _parent_control->GetX();
		int y = _parent_control->GetY();

		int width = this->GetWidth();
		int height = this->GetHeight();

		this->SetBoundingRect(x, y, width, height);

		_triangle->SetBoundingRect(x + 5, y + 5, width / 2, height / 2);

		return;
	}

	if (d == Triangle::TriangleDirection::RIGHT) {

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

	

	if (cd.MouseInWindow(_my_parent_window->GetWinPtr()) && cd.MouseInControl(this)) {

		SDL_SetRenderDrawColor(_render, _mouse_over_color.r, _mouse_over_color.g, _mouse_over_color.b, _mouse_over_color.a);
		SDL_RenderFillRect(_render, &_bounding_rect);
		_triangle->SetColor(255,255,255, 1);
		_triangle->Draw();

	}
	else {
		
		SDL_SetRenderDrawColor(_render, _color.r, _color.g, _color.b, _color.a);
 		SDL_RenderFillRect(_render, &_bounding_rect);
		_triangle->SetColor(228, 209, 230, 1);
		_triangle->Draw();

	}
		
}
