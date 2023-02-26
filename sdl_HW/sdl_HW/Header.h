#pragma once
#include "Control.h"
#include "BorderLine.h"
#include "CloseButton.h"

class Header : public Control
{
private:
	CloseButton _close_button;
	BorderLine _border_line;
};

