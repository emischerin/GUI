#pragma once
#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "Control.h"
#include "Primitives.h"


class ScrollBarButton;
class ScrollBarCaret;
class Scene;

class ScrollBar : public Control
{
public:


	enum ScrollbarPosition
	{
		DOWN,
		RIGHT
	};

	ScrollBar(Scene* scene);

	void ReactToEvents() override;
	void Draw() override;


	~ScrollBar();

private:
	ScrollBarButton* _left_up = nullptr;
	ScrollBarButton* _right_down = nullptr;
	ScrollBarCaret* _caret = nullptr;
	

};
#endif

