#include "ScrollBar.h"
#include "ScrollBarButton.h"
#include "ScrollBarCaret.h"
#include "Scene.h"

ScrollBar::ScrollBar(Scene* scene,ScrollBarPosition position) : Control(scene)
{
	ScrollBarButton* _up = new ScrollBarButton(Triangle::TriangleDirection::UP, this);
	ScrollBarButton* _down = new ScrollBarButton(Triangle::TriangleDirection::DOWN, this);
	ScrollBarCaret* _caret = new ScrollBarCaret(this);

	_up->SetColor(100, 255, 10, 0);
	_up->SetMouseOverColor(99, 150, 87, 0);


	_down->SetColor(100, 255, 10, 0);
	_down->SetMouseOverColor(99, 150, 87, 0);

	

	_down->SetPosition(this->GetX(), (this->GetY() + this->GetHeight()) - 20);

	this->AddChild(_up);
	this->AddChild(_down);
	this->AddChild(_caret);



	

}

void ScrollBar::SetWidthAndHeight(int width, int height)
{
	Control::SetWidthAndHeight(width, height);
	
	


}

void ScrollBar::SetPosition(int x, int y)
{
	Control::SetPosition(x, y);

	
}

void ScrollBar::ReactToEvents()
{

}

void ScrollBar::Update()
{
	int w_height = _my_parent_window->GetWinHeight();
	int w_width = _my_parent_window->GetWinWidth();
	int _offst_x = w_width - _parent_control->GetX();
	int _offset_y = w_height - _parent_control->GetY();
	

	this->SetWidthAndHeight(20, w_height - _offset_y);
	this->SetPosition((this->GetX() + this->GetWidth()) - this->GetWidth(), _offset_y);
}

void ScrollBar::Draw()
{
	SDL_SetRenderDrawColor(_render, 0, 0, 0, 255);
	SDL_RenderFillRect(_render, &_bounding_rect);
	
	Control::Draw();

	
}
