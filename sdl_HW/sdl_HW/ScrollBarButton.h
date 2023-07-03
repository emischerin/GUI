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
	Triangle* _triangle = nullptr;
};
#endif

