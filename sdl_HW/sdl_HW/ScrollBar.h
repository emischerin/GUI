#pragma once
#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "Control.h"
#include "Primitives.h"
#include "ScrollBarButton.h"
#include "ScrollBarCaret.h"
#include "Scene.h"

class ScrollBar : public Control
{
public:
	enum ScrollbarPosition
	{
		DOWN,
		RIGHT
	};



private:
	ScrollBarButton _left_up;
	ScrollBarButton _right_down;
	ScrollBarCaret _caret;
	

};
#endif

