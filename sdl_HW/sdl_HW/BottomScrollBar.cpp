#include "BottomScrollBar.h"
#include "ScrollBarButton.h"
#include "ScrollBarCaret.h"
#include "Viewport.h"

BottomScrollBar::BottomScrollBar(Viewport* viewport) : BaseScrollBar(viewport)
{

	if (!viewport) return;

	_viewport = viewport;

	_left = new ScrollBarButton(Triangle::TriangleDirection::LEFT, this);
	_right = new ScrollBarButton(Triangle::TriangleDirection::RIGHT, this);
	_caret = new ScrollBarCaret(this);

	//_up->SetColor(62,19,66,1);
	_left->SetColor(75, 36, 78, 1);
	_left->SetMouseOverColor(191, 125, 255, 1);
	_left->SetWidthAndHeight(20, 20);

	_right->SetColor(75, 36, 78, 1);
	_right->SetMouseOverColor(191, 125, 255, 0);
	_right->SetWidthAndHeight(20, 20);

	this->SetHeight(20);

}

void BottomScrollBar::ReactToEvents()
{

}

void BottomScrollBar::Update()
{
	int p_height = _parent_control->GetHeight();
	int _this_height = this->GetHeight();
	int _this_x = _parent_control->GetX();
	int _this_y = _parent_control->GetY() + _parent_control->GetHeight() - this->GetHeight();
	
	this->SetWidthAndHeight(_parent_control->GetWidth(), _this_height);

	this->TrimMyWidthIfRightScrollBar();

	this->SetPosition(_this_x, _this_y);

	Control::Update();
}

void BottomScrollBar::Draw()
{
	SDL_SetRenderDrawColor(_render, 15, 8, 18, 255);
	SDL_RenderFillRect(_render, &_bounding_rect);

	Control::Draw();


}

void BottomScrollBar::TrimMyWidthIfRightScrollBar()
{
	ControlMsg msg = { Viewport::ControlMsgRequest::_RIGHT_SCROLLBAR_WIDTH,0 };

	_parent_control->ControlMessagingFunction(&msg);

	this->ResizeWidth(-(int)msg._result);
}