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
	_up->SetWidthAndHeight(20, 20);

	_down->SetColor(100, 255, 10, 0);
	_down->SetMouseOverColor(99, 150, 87, 0);
	_down->SetWidthAndHeight(20, 20);
	

	


}

void ScrollBar::ReactToEvents()
{

}

void ScrollBar::Update()
{
	int w_height = _my_parent_window->GetWinHeight();
	int _this_height = w_height - _parent_control->GetY();
	int _this_x = (_parent_control->GetX() + _parent_control->GetWidth()) - this->GetWidth();

	this->SetWidthAndHeight(this->GetWidth(), _this_height);
	this->SetPosition(_this_x, _parent_control->GetY());

	Control::Update();
}

void ScrollBar::Draw()
{
	SDL_SetRenderDrawColor(_render, 0, 0, 0, 255);
	SDL_RenderFillRect(_render, &_bounding_rect);
	
	Control::Draw();

	
}
