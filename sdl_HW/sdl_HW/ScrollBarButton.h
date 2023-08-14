#pragma once
#ifndef SCROLLBARBUTTON_H
#define SCROLLBARBUTTON_H

#include "CollisionDetector.h"
#include "Triangle.h"

class BaseScrollBar;

class ScrollBarButton: public Control
{	
public:
	
	ScrollBarButton(Triangle::TriangleDirection dir,BaseScrollBar* parent);

	
	void Update() override;
	void Draw() override;

private:
	Triangle* _triangle = nullptr;

	BaseScrollBar* _scroll_bar = nullptr;
};
#endif

