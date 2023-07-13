#include "ScrollBar.h"
#include "ScrollBarButton.h"
#include "ScrollBarCaret.h"
#include "Viewport.h"

ScrollBar::ScrollBar(Viewport* viewport,ScrollBarPosition position) : Control(viewport)
{

	if (!viewport) return;

	_viewport = viewport;

	_up = new ScrollBarButton(Triangle::TriangleDirection::UP, this);
	_down = new ScrollBarButton(Triangle::TriangleDirection::DOWN, this);
	_caret = new ScrollBarCaret(this);

	//_up->SetColor(62,19,66,1);
	_up->SetColor(75, 36, 78, 1);
	_up->SetMouseOverColor(191,125,255, 1);
	_up->SetWidthAndHeight(20, 20);

	_down->SetColor(75,36,78,1);
	_down->SetMouseOverColor(191,125,255, 0);
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
	SDL_SetRenderDrawColor(_render, 15, 8, 18, 255);
	SDL_RenderFillRect(_render, &_bounding_rect);
	
	Control::Draw();

	
}

 void* ScrollBar::ControllMessagingFunction(void* arg1)
{
	 return (void*)1;/**/
}
