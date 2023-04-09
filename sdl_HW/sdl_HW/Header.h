#pragma once
#include "BorderLine.h"
#include "Control.h"

#include "CloseButton.h"
#include "AppGlobals.h"

class Header : public Control
{
public:
	Header(int height,int buttons_width);

	void Draw() override;

	
private:
	CloseButton _close_button;
	BorderLine _border_line;
	int _height= 0;
	
	

	
	
	
	void DrawHeaderRect();
	void DrawCloseButton();
};


