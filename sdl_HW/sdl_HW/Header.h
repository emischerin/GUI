#pragma once
#include "Control.h"
#include "BorderLine.h"
#include "CloseButton.h"

class Header : public Control
{
public:
	Header(int rel_y,int buttons_width);

	void ImplBehaviour() override;

private:
	CloseButton _close_button;
	BorderLine _border_line;
	int rel_y = 0;
	int _buttons_width = 0;
};

