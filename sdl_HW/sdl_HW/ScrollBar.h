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


	~ScrollBar();

private:
	ScrollBarButton* _left_up = nullptr;
	ScrollBarButton* _right_down = nullptr;
	ScrollBarCaret* _caret = nullptr;
	

};
#endif

