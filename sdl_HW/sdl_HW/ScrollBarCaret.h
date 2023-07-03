#pragma once
#ifndef SCROLLBARCARET_H
#define SCROLLBARCARET_H
#include "Control.h"
#include "ScrollBar.h"


class ScrollBarCaret : public Control
{
public:
	ScrollBarCaret(ScrollBar* parent);

	void ReactToEvents() override;
	void Draw() override;
};
#endif
