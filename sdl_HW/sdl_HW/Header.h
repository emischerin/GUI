#pragma once
#include "Control.h"
#include "BorderLine.h"
#include "CloseButton.h"

class Header : public Control
{
public:
	Header(SDL_Window* w,int rel_y);

	void Draw() override;

	void SetParentWindow(SDL_Window* w) override;
private:
	CloseButton _close_button;
	BorderLine _border_line;
	int _rel_y = 0;
	
	SDL_Window* _parent_window = nullptr;
	
	void DrawHeaderRect();
	void DrawCloseButton();
};


