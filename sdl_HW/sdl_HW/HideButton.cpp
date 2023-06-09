#include "HideButton.h"

HideButton::HideButton()
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;
}

HideButton::HideButton(Control* parent) : Control(parent)
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;
}

HideButton::HideButton(SDL_Window* parent)
{
	_color.r = 146;
	_color.g = 7;
	_color.b = 173;
	_color.a = 1;
	_parent_window = parent;

}

void HideButton::ReactToEvents()
{

}

void HideButton::Draw()
{

}

void HideButton::SetParentControl(Control* parent)
{
	this->_parent_control = parent;

	SDL_Rect* p_rect = _parent_control->GetBoundingRect();
	p_rect->w -= _bounding_rect.w;
}
