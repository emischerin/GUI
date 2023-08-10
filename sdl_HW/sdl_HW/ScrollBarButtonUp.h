#pragma once
#ifndef SCROLLBARBUTTONUP_H
#define SCROLLBARBUTTONUP_H
#include "ScrollBarButton.h"
#include "Triangle.h"
#include "CollisionDetector.h"

class BaseScrollBar;


class ScrollBarButtonUp : public ScrollBarButton
{
public:
	ScrollBarButtonUp(Triangle::TriangleDirection dir, BaseScrollBar* parent);
	void ReactToEvents() override;
};
#endif // !
