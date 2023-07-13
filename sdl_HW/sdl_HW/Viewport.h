#pragma once
#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <vector>
#include <queue>
#include <algorithm>
#include "Control.h"
#include "Primitives.h"
#include "Scrollbar.h"
#include "Control.h"
#include "Window.h"

class Viewport : public Control
{
public:
	Viewport(Window* parent_w);


	void AddControl(Control* parent);
	void AddPrimitive(Primitive* p) override;

	void Update() override;

	void Draw() override;



	bool NeedBottomScrollbar();
	bool NeedRightScrollbar();

protected:
	void SetViewportRect();
private:
	SDL_Rect _viewport_rect = { 0,0,0,1 };

	bool _has_bottom_scrollbar = false;
	bool _has_right_scrollbar = false;

	ScrollBar* _scroll_bar = nullptr;
};
#endif

