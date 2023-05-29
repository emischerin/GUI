#include "ResizeButton.h"

ResizeButton::ResizeButton()
{
	_r = 146;
	_g = 7;
	_b = 173;
	_a = 1;

	_bounding_rect.x = _x;
	_bounding_rect.y = _y;
	_bounding_rect.w = _width;
	_bounding_rect.h = _height;
}

void ResizeButton::ReactToEvents()
{

}

void ResizeButton::Draw()
{

}
