#pragma once

#ifndef SCROLLBARBUTTONDOWN_H
#define SCROLLBARBUTTONDOWN_H
#include "ScrollBarButton.h"
#include "Triangle.h"
#include "CollisionDetector.h"
#include "RightScrollBar.h"
#include "Scene.h"

class ScrollBarButtonDown : public ScrollBarButton
{
public:
	ScrollBarButtonDown(Triangle::TriangleDirection dir, BaseScrollBar* parent);
	void ReactToEvents() override;
};
#endif
