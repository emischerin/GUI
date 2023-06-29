#pragma once
#ifndef SCROLLBARBUTTON_H
#define SCROLLBARBUTTON_H
#include "Button.h"
#include "Triangle.h"

class ScrollBarButton: public Button
{
public:
	
	ScrollBarButton(Triangle::TriangleDirection dir);

	void ReactToEvents() override;
	void Draw() override;

private:
	Triangle _triangle = {_bounding_rect.x,_bounding_rect.y,_bounding_rect.w,_bounding_rect.h};
};
#endif

