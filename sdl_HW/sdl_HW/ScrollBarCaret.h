#pragma once
#ifndef SCROLLBARCARET_H
#define SCROLLBARCARET_H
#include "Control.h"
#include "ScrollBar"


class ScrollBarCaret : public Control
{
	ScrollBarCaret(ScrollBar* parent);

	void ReactToEvents() override;
	void Draw() override;
};
#endif
