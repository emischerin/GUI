#pragma once
#ifndef SCROLLBARBUTTON_H
#define SCROLLBARBUTTON_H

#include "CollisionDetector.h"
#include "Triangle.h"

class ScrollBar;

class ScrollBarButton: public Control
{
public:
	
	ScrollBarButton(Triangle::TriangleDirection dir,ScrollBar* parent);

	void ReactToEvents() override;
	void Draw() override;

private:
	Triangle _triangle = {_bounding_rect.x,_bounding_rect.y,_bounding_rect.w,_bounding_rect.h};
};
#endif

