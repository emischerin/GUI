#pragma once
#ifndef HEADER_H
#define HEADER_H

#include "AppGlobals.h"
#include "CloseButton.h"
#include "ResizeButton.h"


class Header : public Control
{
public:
	Header(int height,int buttons_width);

	void ReactToEvents() override;

	void Draw() override;

	
	
private:
	CloseButton _close_button;
	ResizeButton _resize_button;
	int _height= 0;
	int _sys_btns_width = 0;
	
	void MoveWindow();
	
	
	
	void DrawHeaderRect();
	void DrawResizeButton();
	void DrawCloseButton();

	
};

#endif
