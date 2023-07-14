#pragma once
#ifndef SCROLLBARCARET_H
#define SCROLLBARCARET_H
#include "Control.h"
#include "BaseScrollBar.h"
#include "CollisionDetector.h"


class ScrollBarCaret : public Control
{
public:
	ScrollBarCaret(BaseScrollBar* parent);

	void ReactToEvents() override;
	void Update() override;
	void Draw() override;

private:
	BaseScrollBar* _scrollbar = nullptr;
};
#endif
