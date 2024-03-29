#pragma once
#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <vector>
#include <queue>
#include <algorithm>
#include "Control.h"
#include "Primitives.h"
#include "RightScrollBar.h"
#include "BottomScrollBar.h"
#include "Control.h"
#include "Window.h"


class Viewport : public Control
{
public:

	enum ControlMsgRequest
	{
		_RIGHT_SCROLLBAR_WIDTH = 1,
		_BOTTOM_SCROLLBAR_HEIGHT

	};

	Viewport(Window* parent_w);




	void Update() override;
	
	void Draw() override;



	bool NeedBottomScrollbar();
	bool NeedRightScrollbar();

	void DrawScrollBar();



	

	void RemoveScene();

	SDL_Rect* GetViewportRect();

	SDL_Rect* GetViewportRectInScene();

	~Viewport() override;

protected:
	
	void DefineOffsets();

	void ControlMessagingFunction(ControlMsg* message) override;


private:

	


	int _offset_x = 0;
	int _offset_y = 0;

	int _viewport_offset_x = 0;
	int _viewport_offset_y = 0;

	SDL_Rect _viewport_rect = { 0,0,0,1 };
	SDL_Rect _viewport_rect_in_scene = { 0,0,0,1 };

	bool _has_bottom_scrollbar = false;
	bool _has_right_scrollbar = false;

	RightScrollBar* _right_scroll_bar = nullptr;
	BottomScrollBar* _bottom_scroll_bar = nullptr;


	


};
#endif

