#pragma once
#ifndef HEADER_H
#define HEADER_H

#include "AppGlobals.h"
#include "Control.h"
#include "CloseButton.h"
#include "ResizeButton.h"
#include "HideButton.h"
#include "Window.h"


class Header : public Control
{
public:
	Header(int height,int buttons_width);

	Header(int height, int buttons_width, Window* parent_window);

	void ReactToEvents() override;

	void Draw() override;

	int GetLayer() override;
	
private:
	CloseButton _close_button;
	ResizeButton _resize_button;
	HideButton _hide_button;

	int _height= 0;
	int _sys_btns_width = 0;
	
	SDL_Rect _parent_window_geometry = { 0,0,0,0 };
	
	
	
	
	void DrawHeaderRect();
	void DrawResizeButton();
	void DrawCloseButton();
	void DrawHideButton();
	
};

#endif
