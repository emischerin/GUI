#pragma once
#include <SDL.h>
#include "BorderLine.h"
#include "Control.h"

#include "CloseButton.h"
#include "ResizeButton.h"
#include "AppGlobals.h"

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
	
	

	
	
	
	void DrawHeaderRect();
	void DrawResizeButton();
	void DrawCloseButton();
};


