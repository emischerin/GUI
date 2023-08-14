#include "RightScrollBar.h"
#include "ScrollBarButton.h"
#include "ScrollBarButtonUp.h"
#include "ScrollBarButtonDown.h"
#include "ScrollBarCaret.h"
#include "Scene.h"

RightScrollBar::RightScrollBar()
{
	_up = new ScrollBarButtonUp(Triangle::TriangleDirection::UP, this);
	_down = new ScrollBarButtonDown(Triangle::TriangleDirection::DOWN, this);
	_caret = new ScrollBarCaret(this);

	//_up->SetColor(62,19,66,1);
	_up->SetColor(75, 36, 78, 1);
	_up->SetMouseOverColor(191, 125, 255, 1);
	_up->SetWidthAndHeight(20, 20);

	_down->SetColor(75, 36, 78, 1);
	_down->SetMouseOverColor(191, 125, 255, 0);
	_down->SetWidthAndHeight(20, 20);

	this->SetWidth(20);
}

RightScrollBar::RightScrollBar(Control* parent) : BaseScrollBar(parent)
{

	

	_up = new ScrollBarButtonUp(Triangle::TriangleDirection::UP, this);
	_down = new ScrollBarButtonDown(Triangle::TriangleDirection::DOWN, this);
	_caret = new ScrollBarCaret(this);

	//_up->SetColor(62,19,66,1);
	_up->SetColor(75, 36, 78, 1);
	_up->SetMouseOverColor(191,125,255, 1);
	_up->SetWidthAndHeight(20, 20);

	_down->SetColor(75,36,78,1);
	_down->SetMouseOverColor(191,125,255, 0);
	_down->SetWidthAndHeight(20, 20);
	
	this->SetWidth(20);
	


}

void RightScrollBar::ReactToEvents()
{
	_up->ReactToEvents();
	_down->ReactToEvents();
}

void RightScrollBar::Update()
{
	int p_height = _parent_control->GetHeight();
	int _this_height = p_height;
	int _this_x = (_parent_control->GetX() + _parent_control->GetWidth()) - this->GetWidth();

	this->SetWidthAndHeight(this->GetWidth(), _this_height);

	this->TrimMyHeightIfBottomScrollbar();

	this->SetPosition(_this_x, _parent_control->GetY());

	Control::Update();
}

void RightScrollBar::Draw()
{
	SDL_SetRenderDrawColor(_render, 15, 8, 18, 255);
	SDL_RenderFillRect(_render, &_bounding_rect);
	
	Control::Draw();

	
}

void RightScrollBar::TrimMyHeightIfBottomScrollbar()
{
	
	ControlMsg msg = { Scene::ControlMsgRequest::_BOTTOM_SCROLLBAR_HEIGHT,0 };

	_parent_control->ControlMessagingFunction(&msg);

	this->ResizeHeight(-(int)msg._result);
	
}

void RightScrollBar::ControlMessagingFunction(ControlMsg* message)
{
	if (!message) return;

	Scene* scene = static_cast<Scene*>(GetParentControl());

	switch (message->_command)
	{
	case Scene::_SCROLL_UP:
		
		scene->ControlMessagingFunction(message);
		break;
	case Scene::_SCROLL_DOWN:
		scene->ControlMessagingFunction(message);
		break;
		
	}
}
