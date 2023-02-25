#pragma once
#include "Control.h"

class Button : public Control
{
public:
	Button(int x, int y);
private:
	int _mouse_over_r, _mouse_over_g;
	int _mouse_over_b, _mouse_over_a;
};

