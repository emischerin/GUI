#pragma once
#ifndef BASESCROLLBAR_H
#define BASESCROLLBAR_H
#include "Control.h"

class BaseScrollBar : public Control
{
public:

	enum ControlMsgRequest
	{
		_SCROLL_UP = 1
	};
	
	BaseScrollBar();
	BaseScrollBar(Control* parent);
};
#endif

