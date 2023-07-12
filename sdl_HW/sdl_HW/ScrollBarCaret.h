#pragma once
#ifndef SCROLLBARCARET_H
#define SCROLLBARCARET_H
#include "Control.h"
#include "ScrollBar.h"
#include "CollisionDetector.h"


class ScrollBarCaret : public Control
{
public:
	ScrollBarCaret(ScrollBar* parent);

	void ReactToEvents() override;
	void Update() override;
	void Draw() override;

private:
	ScrollBar* _scrollbar = nullptr;
};
#endif
