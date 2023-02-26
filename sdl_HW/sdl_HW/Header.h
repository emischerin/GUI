#pragma once
#include "Control.h"
#include "BorderLine.h"
#include "CloseButton.h"

class Header : public Control
{
public:
	Header(SDL_Window* w,int rel_y,int buttons_width);

	void ImplBehaviour() override;

private:
	CloseButton _close_button;
	BorderLine _border_line;
	int _rel_y = 0;
	int _buttons_width = 0;
	SDL_Window* _parent_window = nullptr;
};


