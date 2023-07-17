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
#include "Scene.h"

class Viewport : public Control
{
public:

	enum ControlMsgRequest
	{
		_RIGHT_SCROLLBAR_WIDTH = 1

	};

	Viewport(Window* parent_w);


	void AddControl(Control* c);
	void AddPrimitive(Primitive* p) override;

	void Update() override;

	void Draw() override;



	bool NeedBottomScrollbar();
	bool NeedRightScrollbar();

	void DrawScrollBar();

	bool HasRightScrollBar() const;
	bool HasBottomScrollBar() const;

	void SetScene(Scene* scene);

	void RemoveScene();

protected:
	void SetViewportRect();
	void DefineOffsets();

	void ControlMessagingFunction(ControlMsg* message) override;


private:

	void CreateRightScrollBar();
	void RemoveRightScrollBar();

	void CreateBottomScrollBar();
	void RemoveBottomScrollBar();


	int _offset_x = 0;
	int _offset_y = 0;

	SDL_Rect _viewport_rect = { 0,0,0,1 };

	bool _has_bottom_scrollbar = false;
	bool _has_right_scrollbar = false;

	RightScrollBar* _right_scroll_bar = nullptr;
	BottomScrollBar* _bottom_scroll_bar = nullptr;


	Scene* _scene = nullptr;


};
#endif

