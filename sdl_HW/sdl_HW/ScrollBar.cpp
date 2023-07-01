#include "ScrollBar.h"

ScrollBar::~ScrollBar()
{
	delete _left_up;
	delete _right_down;
	delete _caret;
}