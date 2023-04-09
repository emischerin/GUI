#pragma once
#include "Control.h"
#include "BorderLine.h"
#include "CloseButton.h"

class Header : public Control
{
public:
	Header(SDL_Window* w,int height,int buttons_width);

	void Draw() override;

	void SetParentWindow(SDL_Window* w) override;
private:
	CloseButton _close_button;
	BorderLine _border_line;
	int _height= 0;
	
	SDL_Window* _parent_window = nullptr;

	SDL_Rect _bounding_rect; /* for window movement with mouse*/
	
	
	void DrawHeaderRect();
	void DrawCloseButton();
};


